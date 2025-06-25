#include "map.h"
#include <QVBoxLayout>
#include <QDebug>

Map::Map(QWidget *parent) : QWidget(parent) {
    // 初始化场景和视图
    m_scene = new QGraphicsScene(this);
    m_view = new QGraphicsView(m_scene, this);
    m_view->setRenderHint(QPainter::SmoothPixmapTransform);
    m_view->setAlignment(Qt::AlignCenter);
    m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // 设置布局
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_view);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    // 加载地图
    loadMap();

    // 添加测试景点
    addSpot("测试1，这是对景点1的详细描述......撒旦看海去开挖好像卡我hi幸亏我还"
            "是的咯今晚皇帝哈维i大涨价物价很低啊"
            "阿斯顿hi哇还得靠自己啊和我i打开哈伦裤"
            "啊就是的炸我哭着大哭为黄帝问哈展开"
            "螯合物贷款机构合作五i啊个单子u我", QPointF(300, 200));
    addSpot("测试2，这是对景点2的详细描述......", QPointF(500, 350));
    addSpot("测试3，这是对景点3的详细描述......", QPointF(600, 350));
}

void Map::loadMap() {
    m_mapPixmap.load("://recource_image/map.png");
    if (m_mapPixmap.isNull()) {
        qDebug() << "Failed to load map image!";
        return;
    }

    m_mapItem = m_scene->addPixmap(m_mapPixmap);
    m_scene->setSceneRect(m_mapPixmap.rect());
}

void Map::addSpot(const QString &name, const QPointF &scenePos) {
    auto *spot = new ClickableRectItem(name);
    spot->setRect(0, 0, 30, 20);
    spot->setPos(scenePos);
    spot->setData(0, scenePos); // 存储原始位置到item的data中
    m_scene->addItem(spot);
    m_spotItems.append(spot);

    // 连接
    connect(spot, &ClickableRectItem::clicked,
            this, &Map::handleSpotClick);
}

void Map::updateSpotPositions() {
    if (!m_mapItem || m_spotItems.isEmpty()) return;

    // 获取当前地图的缩放变换
    QTransform mapTransform = m_mapItem->transform();
    // 获取当前地图的缩放比例
    qreal mapScale = m_mapItem->scale();

    // 更新所有景点的位置
    for (auto *spot : m_spotItems) {
        // 将场景坐标转换为视图坐标，再应用逆变换
        QPointF originalPos = spot->data(0).toPointF(); // 存储的原始位置
        QPointF scaledPos = mapTransform.map(originalPos);
        spot->setPos(scaledPos);

        // 让标记随地图同步缩放
        spot->setScale(mapScale);
    }
}

void Map::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);

    if (m_mapPixmap.isNull()) return;

    // 获取有效视图尺寸（排除滚动条占用空间）
    qreal viewWidth = m_view->viewport()->width() - 10; // 留出边距
    qreal viewHeight = m_view->viewport()->height() - 10;

    // 计算理论缩放比例
    qreal scale = qMin(
        viewWidth / m_mapPixmap.width(),
        viewHeight / m_mapPixmap.height()
        );

    // 动态调整策略
    if (scale < 0.1) {
        // 当窗口过小时：
        // 1. 保持最小缩放
        scale = 0.1;
        // 2. 自动显示滚动条
        m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    } else {
        // 正常大小时隐藏滚动条
        m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    }

    // 应用变换
    m_mapItem->setTransform(QTransform::fromScale(scale, scale));
    m_view->setSceneRect(m_mapItem->boundingRect());
    updateSpotPositions();
}

void Map::handleSpotClick(const QString &spotName) {
    // 创建详情窗口（不设置父对象，作为独立窗口）
    DetailWindow *detailWin = new DetailWindow(spotName);
    detailWin->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动删除

    // 设置模态，防止同时打开多个窗口
    detailWin->setWindowModality(Qt::ApplicationModal);

    // 居中显示
    QRect screenGeometry = QApplication::primaryScreen()->geometry();
    int x = (screenGeometry.width() - detailWin->width()) / 2;
    int y = (screenGeometry.height() - detailWin->height()) / 2;
    detailWin->move(x, y);

    detailWin->show();
}

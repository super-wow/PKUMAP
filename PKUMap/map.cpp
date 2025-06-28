#include "map.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>

Map::Map(QWidget *parent) : QWidget(parent) {
    // 初始化场景和视图
    m_scene = new QGraphicsScene(this);
    m_view = new QGraphicsView(m_scene, this);
    m_view->setRenderHint(QPainter::SmoothPixmapTransform);
    m_view->setAlignment(Qt::AlignCenter);
    m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    setupSearchUI();

    // 初始化搜索结果标记
    searchResultMarker = new QGraphicsRectItem();
    searchResultMarker->setRect(0, 0, 40, 40);
    searchResultMarker->setPen(QPen(Qt::green, 3));
    searchResultMarker->setBrush(Qt::NoBrush);
    searchResultMarker->setZValue(10); // 确保在最上层
    searchResultMarker->hide(); // 初始隐藏
    m_scene->addItem(searchResultMarker);

    // 加载地图
    loadMap();

    // 添加测试景点
    addSpot("蔚秀园位于北京大学校园内，是校内著名的园林景观之一。"
            "园内绿树成荫，亭台楼阁点缀其间，环境清幽雅致。"
            "这里曾是清代皇家园林的一部分，历史悠久文化深厚。"
            "现为师生休闲、读书、交流的理想场所，充满学术氛围。"
            "春日百花争艳，夏日荷风送爽，秋日红叶满园，冬日雪景如画。"
            "园中湖面波光粼粼，倒映着周围的古建筑，别具韵味。"
            "常有学子在此晨读、讨论，传承着北大的治学精神。"
            "蔚秀园见证了无数北大人的成长故事，承载着美好记忆。", QPointF(310, 210));
    addSpot("北大校史馆坐落于燕园核心区，是展示学校历史的殿堂。"
            "建筑风格典雅庄重，与周边环境和谐相融独具特色。"
            "馆内珍藏丰富史料，记录北大自1898年创办至今历程。"
            "通过珍贵文物、照片和文献，展现中国近代教育发展。"
            "重点呈现五四运动、西南联大等重大历史事件贡献。"
            "设有专题展览区，定期更新展示北大最新学术成果。"
            "是新生入学教育重要场所，传承北大精神文化根基。"
            "每年吸引众多访客，成为了解中国高等教育的重要窗口。", QPointF(480, 380));
    addSpot("梅石碑立于北大未名湖畔，是校园著名文化景观之一。"
            "石碑镌刻清代乾隆皇帝御笔题诗，具有珍贵历史价值。"
            "原为圆明园遗物，后移至此地，见证近代历史变迁。"
            "碑身梅纹雕刻精美，展现中国传统石刻艺术精髓。"
            "与周边湖光塔影相映成趣，构成北大标志性风景。"
            "常有师生在此驻足观赏，感受传统文化艺术魅力。"
            "石碑保存完好，校方定期维护确保文物安全传承。"
            "既是重要历史文物，也是北大文化底蕴的生动体现。", QPointF(600, 350));
    addSpot("畅春园位于北大西门外，是清代皇家园林杰出代表。"
            "康熙年间建成，曾为帝王理政游憩的重要场所。"
            "园林设计融合南北风格，展现古代造园艺术巅峰。"
            "园内原有殿堂楼阁三十余座，规模宏大气势恢宏。"
            "现遗址区域已纳入保护，留存部分建筑基址遗存。"
            "与北大校园相邻，形成古今交融的独特文化景观。"
            "定期举办考古成果展，再现昔日皇家园林风貌。"
            "是研究清代园林史和北京历史地理的重要实证。", QPointF(350,380));
    addSpot("北大华表矗立于办公楼前，是校园标志性文物之一。"
            "原为圆明园安佑宫遗物，1925年迁至燕京大学校园。"
            "汉白玉材质精雕细琢，展现清代石刻艺术巅峰水平。"
            "柱身蟠龙纹饰栩栩如生，云纹雕刻飘逸灵动传神。"
            "与贝公楼形成中轴线，构成北大核心景观区。"
            "历经百年风雨沧桑，见证中国近现代教育发展。"
            "校方精心保护修缮，确保文物历史风貌永续传承。"
            "既是珍贵历史遗产，更象征北大精神薪火相传。",QPointF(440,250));
    addSpot("未名湖静卧燕园中央，是北大最负盛名的景观。"
            "湖面如镜映博雅塔影，四季景色各异美不胜收。"
            "春来垂柳拂堤，夏日荷香四溢，秋至枫红似火。"
            "湖畔石舫记载历史，翻尾石鱼诉说百年沧桑。"
            "朱自清笔下荷塘月色，让未名湖享誉海内外。"
            "晨读学子身影点缀，构成北大独特人文画卷。"
            "湖心岛树木葱郁，成为各类珍禽栖息乐园。"
            "未名二字寓意深远，象征北大永不止步精神。",QPoint(720,310));
    addSpot("北大图书馆矗立校园中心，是知识的圣殿与象征。"
            "百年积淀藏书浩瀚，典籍文献逾千万册规模。"
            "李大钊曾任馆长，见证新文化运动重要历程。"
            "古籍善本珍藏丰富，四库全书等瑰宝熠熠生辉。"
            "现代化设施完善，智能服务提升学术研究体验。"
            "阅览室宽敞明亮，常驻学子潜心研读的身影。"
            "建筑中西合璧风格，彰显北大开放包容气质。"
            "昼夜不息的求知灯火，照亮无数学术追梦之路。",QPoint(680,450));
    addSpot("博雅塔巍然矗立未名湖畔，是北大标志性景观。"
            "原为水塔功能建筑，后成燕园文化精神象征。"
            "塔身十三层密檐式设计，展现中国传统建筑之美。"
            "与未名湖相映成趣，构成一塔湖图经典画面。"
            "登临可俯瞰燕园全景，四季风光尽收眼底。"
            "塔名取博雅之意，寄托对学子成才的期许。"
            "历经近百年风雨，见证北大学术传统代代相传。"
            "既是实用建筑杰作，更是北大精神的永恒地标。",QPoint(760,340));
    addSpot("北大西门庄严典雅，是燕园最具标志性的入口。"
            "传统宫门式建筑风格，彰显百年学府深厚底蕴。"
            "朱红大门金钉排列，上方匾额题写校名苍劲有力。"
            "门前石狮威武肃穆，守护着学术殿堂的庄严。"
            "每日迎来送往无数学子，见证青春梦想的启航。"
            "建筑细节精雕细琢，体现中国传统建筑艺术精髓。"
            "夜幕下华灯初上，更显古朴大气的独特韵味。"
            "既是校园地理坐标，更是北大精神的文化象征。",QPoint(420,290));
    addSpot("革命烈士纪念馆庄严肃穆，坐落于燕园之内。"
            "馆内陈列着为革命献身的北大英烈事迹与文物。"
            "真实记录五四运动以来师生爱国奋斗的光辉历程。"
            "通过历史照片、文献资料展现先烈崇高革命精神。"
            "每年清明时节师生前来祭扫，缅怀先烈丰功伟绩。"
            "馆舍建筑简朴庄重，环境清幽适合追思与瞻仰。"
            "作为爱国主义教育基地，传承红色基因与革命传统。"
            "激励当代北大人不忘初心，砥砺前行报效祖国。",QPoint(590,450));
    addSpot("燕南园坐落北大校园南部，是著名学者聚居区。"
            "青砖灰瓦庭院深深，保留传统四合院建筑格局。"
            "曾居住过冯友兰、朱光潜等众多学术大师。"
            "园中古树参天蔽日，环境清幽适合治学研究。"
            "一砖一瓦皆承载着北大厚重的学术传统记忆。"
            "现存建筑保存完好，展现民国时期建筑特色。"
            "常有访客慕名而来，追寻大师足迹感受文脉。"
            "既是历史建筑群，更是北大学术精神的活化石。",QPoint(620,590));
    addSpot("三角地位于北大核心区，是校园重要交流空间。"
            "毗邻图书馆与教学楼，形成天然人流聚集场所。"
            "历史上曾是海报栏集中地，承载特殊时代记忆。"
            "现为信息发布中心，各类学术活动公告汇集处。"
            "每日师生穿梭其间，构成校园最活跃的公共区域。"
            "保留北大特有的信息共享与自由讨论传统。"
            "周边绿树环绕，石凳供人休憩交流。"
            "既是地理坐标，更是北大开放精神的生动体现。",QPoint(690,620));
    addSpot("百年讲堂矗立燕园中心，是北大文化地标建筑。"
            "红墙绿瓦气势恢宏，融合中西建筑艺术精华。"
            "内设大剧场、音乐厅，常年举办高水平文艺演出。"
            "学术大师讲座云集，诺贝尔奖得主在此开讲。"
            "舞台设备先进完善，可满足各类艺术表演需求。"
            "师生文艺汇演首选地，展现北大美育教育成果。"
            "建筑细节精雕细琢，门廊立柱尽显庄重大气。"
            "既是艺术殿堂，更是北大素质教育重要载体。",QPoint(700,570));
    addSpot("北大餐饮服务区遍布校园，集中于此处。"
            "学一学五食堂菜式丰富，提供各地风味美食。"
            "农园餐厅环境现代，三层空间各具特色功能。"
            "便利超市24小时营业，随时满足生活所需。"
            "咖啡厅书香弥漫，是学术交流的理想场所。"
            "餐饮价格亲民实惠，保障学子生活品质。"
            "既是生活服务区，更展现北大的人文关怀。",QPoint(520,650));
    addSpot("勺园坐落北大校园西北，是国际学术交流中心。"
            "园内建筑典雅别致，融合中西园林设计精华。"
            "主要接待来访学者，促进中外学术文化交流。"
            "客房设施完善舒适，营造温馨学术居住环境。"
            "会议中心设备先进，承办各类高端学术论坛。"
            "餐厅提供多国料理，满足不同文化饮食需求。"
            "绿树成荫环境静谧，适合学者潜心研究思考。"
            "既是接待场所，更是北大国际化的重要窗口。",QPoint(470,500));
    addSpot("五四体育场位于北大东区，是校园运动核心场所。"
            "标准400米跑道环绕，中央铺设优质人工草坪。"
            "以五四运动命名，传承北大爱国进步传统。"
            "看台可容纳数千人，承办校级重大体育赛事。"
            "清晨黄昏运动者众，展现北大人蓬勃朝气。"
            "体育设施完善先进，满足专业训练需求。"
            "周边配套更衣淋浴，提供舒适运动体验。"
            "既是健身场地，更是北大体育精神的象征。",QPoint(830,730));
    addSpot("镜春园静卧燕园东北，是北大古典园林瑰宝。"
            "园内湖面如镜倒映，春来垂柳拂水波光粼粼。"
            "原为清代淑春园部分，历经修葺保存完好。"
            "曲径通幽亭台错落，展现传统造园艺术精髓。"
            "朗润园遗址相邻，构成完整历史园林体系。"
            "常有师生在此写生，感受自然与人文交融。"
            "四季景色变幻多姿，尤以春日景致最负盛名。"
            "既是休憩胜地，更是中国传统园林文化课堂。",QPoint(610,150));

    addRoute();
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



void Map::addRoute() {
    for(int j=1;j<=2;++j){
        if(j==1){
            QList<QPointF> routePoints;
            routePoints << QPointF(420, 290) << QPointF(510, 280) << QPointF(520, 360) << QPointF(580, 385) << QPointF(640,390) << QPointF(700,380) << QPointF(767, 360) << QPointF(760, 340) << QPointF(750, 235) << QPointF(650, 245) << QPointF(640,270) << QPointF(510, 280);

            QPainterPath path;
            path.moveTo(routePoints[0]);
            for (int i = 1; i < routePoints.size(); ++i) {
                QPointF ctrl1 = routePoints[i-1] + (routePoints[i] - routePoints[i-1]) * 0.3;
                QPointF ctrl2 = routePoints[i-1] + (routePoints[i] - routePoints[i-1]) * 0.7;
                path.cubicTo(ctrl1, ctrl2, routePoints[i]);
            }

            auto *routeItem = new ClickablePathItem("绕未名湖漫步一周，尽览北大最精华的景致。"
                                                    "从湖东岸出发，博雅塔影最先映入游人眼帘。"
                                                    "北岸石舫静静停泊，诉说百年学府的沧桑历史。"
                                                    "西侧翻尾石鱼跃水，是毕业生必拍的纪念景点。"
                                                    "南岸垂柳依依，春日嫩绿枝条轻拂湖面。"
                                                    "湖心岛树木葱郁，常有白鹭栖息增添生机。"
                                                    "环湖小径平整舒适，适合晨跑或悠闲散步。"
                                                    "四季景色各异，晨昏光影变幻美不胜收。");
            routeItem->setPath(path);
            routeItem->setData(0, QVariant::fromValue(path)); // 存储原始路径


            m_scene->addItem(routeItem);
            m_routeItems.append(routeItem);

            connect(routeItem, &ClickablePathItem::clicked, this, &Map::handleRouteClick);
        }
        else{
            QList<QPointF> routePoints;
            routePoints << QPointF(750, 810) << QPointF(750, 430) << QPointF(580, 430) << QPointF(580,560) << QPoint(575,570) << QPointF(570,660) <<QPointF(750,660);

            QPainterPath path;
            path.moveTo(routePoints[0]);
            for (int i = 1; i < routePoints.size(); ++i) {
                QPointF ctrl1 = routePoints[i-1] + (routePoints[i] - routePoints[i-1]) * 0.3;
                QPointF ctrl2 = routePoints[i-1] + (routePoints[i] - routePoints[i-1]) * 0.7;
                path.cubicTo(ctrl1, ctrl2, routePoints[i]);
            }

            auto *routeItem = new ClickablePathItem("燕南园坐落北大校园南部，青砖灰瓦庭院深深，"
                                                    "曾居冯友兰等学术大师，承载厚重人文历史。"
                                                    "园内古树参天环境清幽，适合静心治学研究。"
                                                    "保留完整四合院格局，展现民国建筑特色。"
                                                    "常有访客追寻大师足迹，感受学术文脉传承。"
                                                    "北大图书馆矗立校园中心，藏书浩瀚逾千万册。"
                                                    "李大钊曾任馆长，见证新文化运动重要历程。"
                                                    "古籍善本珍藏丰富，四库全书等瑰宝荟萃。"
                                                    "现代化设施完善，智能服务提升研究体验。"
                                                    "昼夜不息的求知灯火，照亮无数学术梦想。");
            routeItem->setPath(path);
            routeItem->setData(0, QVariant::fromValue(path)); // 存储原始路径


            m_scene->addItem(routeItem);
            m_routeItems.append(routeItem);

            connect(routeItem, &ClickablePathItem::clicked, this, &Map::handleRouteClick);
        }
    }


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


void Map::updateRoutePositions() {
    if (!m_mapItem || m_routeItems.isEmpty()) return;

    qreal mapScale = m_mapItem->scale();
    QTransform mapTransform = m_mapItem->transform();

    for (auto *route : m_routeItems) {
        // 保存原始路径数据
        if (route->data(0).isNull()) {
            route->setData(0, QVariant::fromValue(route->path()));
        }

        // 获取原始路径
        QPainterPath originalPath = route->data(0).value<QPainterPath>();
        QPainterPath transformedPath;

        // 对整个路径应用变换（保持贝塞尔曲线结构）
        transformedPath = mapTransform.map(originalPath);

        route->setPath(transformedPath);
        // 不需要单独设置scale，因为变换已包含在mapTransform中
    }
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


void Map::setupSearchUI() {
    // 创建搜索控件
    QWidget *searchPanel = new QWidget(this);
    searchPanel->setFixedWidth(200);

    searchEdit = new QLineEdit(searchPanel);
    searchButton = new QPushButton("搜索", searchPanel);

    QVBoxLayout *panelLayout = new QVBoxLayout(searchPanel);
    panelLayout->addWidget(new QLabel("搜索景点:"));
    panelLayout->addWidget(searchEdit);
    panelLayout->addWidget(searchButton);
    panelLayout->addStretch();

    // 主布局
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(m_view, 1); // 地图占主要空间
    mainLayout->addWidget(searchPanel); // 搜索面板在右侧
    mainLayout->setContentsMargins(0, 0, 0, 0);

    // 连接信号
    connect(searchButton, &QPushButton::clicked, this, &Map::performSearch);
    connect(searchEdit, &QLineEdit::returnPressed, this, &Map::performSearch);
}

void Map::performSearch() {
    QString keyword = searchEdit->text().trimmed();
    if (keyword.isEmpty()) return;

    // 搜索景点
    for (auto *spot : m_spotItems) {
        if (spot->name().contains(keyword, Qt::CaseInsensitive)) {
            showSearchResult(spot->pos());
            return;
        }
    }



    // 未找到结果
    searchResultMarker->hide();
    QMessageBox::information(this, "提示", "未找到匹配的景点");
}

void Map::showSearchResult(const QPointF &position) {
    // 显示绿色框
    searchResultMarker->setRect(position.x() - 20, position.y() - 20, 40, 40);
    searchResultMarker->show();

    // 居中显示结果
    m_view->centerOn(position);

    // 5秒后自动隐藏
    QTimer::singleShot(5000, [this]() {
        searchResultMarker->hide();
    });
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

    if (searchEdit && searchEdit->parentWidget()) {
        searchEdit->parentWidget()->setFixedWidth(200);
    }
    // 应用变换
    m_mapItem->setTransform(QTransform::fromScale(scale, scale));
    m_view->setSceneRect(m_mapItem->boundingRect());
    updateSpotPositions();
    updateRoutePositions();
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

void Map::handleRouteClick(const QString &routeName) {
    DetailWindow *detailWin = new DetailWindow(routeName);
    detailWin->setAttribute(Qt::WA_DeleteOnClose);
    detailWin->setWindowModality(Qt::ApplicationModal);
    detailWin->show();
}

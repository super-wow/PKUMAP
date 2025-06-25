#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "clickablerectitem.h"
#include "detailwindow.h"
#include <QScreen>
#include <QApplication>

class Map : public QWidget {
    Q_OBJECT
public:
    explicit Map(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QGraphicsScene *m_scene;
    QGraphicsView *m_view;
    QGraphicsPixmapItem *m_mapItem;
    QPixmap m_mapPixmap;
    QVector<ClickableRectItem*> m_spotItems;  // 存储所有景点项

    void loadMap();
    void addSpot(const QString &name, const QPointF &scenePos);
    void updateSpotPositions();  // 更新景点位置
private slots:
    void handleSpotClick(const QString &spotName);
};

#endif // MAP_H

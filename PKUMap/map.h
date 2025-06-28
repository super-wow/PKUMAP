#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "clickablerectitem.h"
#include "clickablepathitem.h"
#include "detailwindow.h"
#include <QScreen>
#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsRectItem>

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
    QList<ClickablePathItem*> m_routeItems;

    QLineEdit *searchEdit;
    QPushButton *searchButton;
    QGraphicsRectItem *searchResultMarker; // 用于显示绿色框

    void setupSearchUI();
    void performSearch();
    void showSearchResult(const QPointF &position);

    void loadMap();
    void addRoute();
    void addSpot(const QString &name, const QPointF &scenePos);
    void updateSpotPositions();  // 更新景点位置
    void updateRoutePositions();
private slots:
    void handleSpotClick(const QString &spotName);
    void handleRouteClick(const QString &routeName);
};

#endif // MAP_H

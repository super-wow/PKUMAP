#include "clickablepathitem.h"
#include <QPen>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>

ClickablePathItem::ClickablePathItem(const QString &name, QGraphicsItem *parent)
    : QGraphicsPathItem(parent), m_name(name)
{
    // 设置默认路径样式
    QPen pen(QColor(0, 100, 255), 3);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    setPen(pen);

    setAcceptHoverEvents(true);
}

void ClickablePathItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    emit clicked(m_name);
}

void ClickablePathItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);

    // 获取当前画笔并修改
    QPen p = pen();
    p.setColor(QColor(0, 150, 255));  // 高亮蓝色
    p.setWidth(4);                    // 加粗
    setPen(p);

    setCursor(Qt::PointingHandCursor);
}

void ClickablePathItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);

    // 恢复默认样式
    QPen p = pen();
    p.setColor(QColor(0, 100, 255));  // 普通蓝色
    p.setWidth(3);                    // 恢复宽度
    setPen(p);
}

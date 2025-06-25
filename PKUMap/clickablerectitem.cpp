#include "clickablerectitem.h"

ClickableRectItem::ClickableRectItem(const QString &name, QGraphicsItem *parent)
    : QGraphicsRectItem(parent), m_name(name)
{
    setRect(0, 0, 30, 20);
    setBrush(QColor(255, 0, 0, 80));

    // 创建 QPen 对象并设置样式为 NoPen
    QPen pen(Qt::NoPen);
    setPen(pen);  // 正确传递 QPen 对象

    setAcceptHoverEvents(true);
}

// 鼠标点击事件
void ClickableRectItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);  // 标记未使用的参数
    emit clicked(m_name);  // 发射信号
}

// 鼠标悬停进入
void ClickableRectItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    Q_UNUSED(event);
    setBrush(QColor(255, 0, 0, 150));  // 加深颜色
    setCursor(Qt::PointingHandCursor);  // 手型光标
}

// 鼠标悬停离开
void ClickableRectItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    Q_UNUSED(event);
    setBrush(QColor(255, 0, 0, 80));    // 恢复颜色
}

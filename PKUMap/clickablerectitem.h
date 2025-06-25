#ifndef CLICKABLERECTITEM_H
#define CLICKABLERECTITEM_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QBrush>
#include <QPen>

// 继承 QObject（支持信号槽）和 QGraphicsRectItem（提供矩形图形项）
class ClickableRectItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT  // 必须添加，用于支持信号槽机制

public:
    // 构造函数：参数为景点名称和父项
    explicit ClickableRectItem(const QString &name, QGraphicsItem *parent = nullptr);

    // 重写鼠标事件函数
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

signals:
    // 点击时发射的信号，携带景点名称
    void clicked(const QString &name);

private:
    QString m_name;  // 存储景点名称
};

#endif // CLICKABLERECTITEM_H

#ifndef CLICKABLEPATHITEM_H
#define CLICKABLEPATHITEM_H

#include <QGraphicsPathItem>
#include <QObject>

class ClickablePathItem : public QObject, public QGraphicsPathItem {
    Q_OBJECT
public:
    explicit ClickablePathItem(const QString &name, QGraphicsItem *parent = nullptr);
    QString name() const { return m_name; }

signals:
    void clicked(const QString &name);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

private:
    QString m_name;

};

#endif // CLICKABLEPATHITEM_H

#ifndef DELEGATEATLETI_H
#define DELEGATEATLETI_H

#include <QItemDelegate>
#include <QAbstractItemModel>
#include <QEvent>
#include <QModelIndex>
#include <QStyleOptionViewItem>

class DelegateAtleti : public QItemDelegate
{
    Q_OBJECT
public:
    DelegateAtleti();
    DelegateAtleti(QObject *parent = nullptr);
    void paint(QPainter*, const QStyleOptionViewItem&, const QModelIndex&) const override;
    bool editorEvent(QEvent*, QAbstractItemModel*,
                     const QStyleOptionViewItem &, const QModelIndex &) override;
};

#endif // DELEGATEATLETI_H

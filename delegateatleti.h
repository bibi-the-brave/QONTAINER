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
    DelegateAtleti(QObject *parent = nullptr);
    void paint(QPainter*, const QStyleOptionViewItem&, const QModelIndex&) const override;
    bool editorEvent(QEvent*, QAbstractItemModel*,
                     const QStyleOptionViewItem &, const QModelIndex &) override;

private:
    void visualizzaMessaggio(const QString&);

    typedef QMap<QModelIndex, QStyleOptionButton*> bottoniEliminazione; // per risparmiare anni di vita
    bottoniEliminazione btnEl;

signals:
    void avvisoEliminazione(int); //serve per avvisare che l'utente vuole eliminare una riga

public slots:
    void slotEliminazione(int);
};

#endif // DELEGATEATLETI_H

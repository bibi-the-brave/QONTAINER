#include "delegateatleti.h"
#include <QtGlobal>
#include <QDialog>
#include <QApplication>
#include <QAbstractItemModel>
#include <QEvent>
#include <QModelIndex>
#include <QStyleOptionViewItem>
#include <QMouseEvent>
#include <QPainter>

DelegateAtleti::DelegateAtleti(QObject *parent) : QItemDelegate (parent) {}

void DelegateAtleti::paint(QPainter *painter, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const
{
    QStyleOptionButton* bottone = btnEl.value(index);
    if (!bottone) {
        bottone = new QStyleOptionButton();
        bottone->text = "Elimina";
        bottone->state |= QStyle::State_Enabled;
        (const_cast<DelegateAtleti *>(this))->btnEl.insert(index, bottone);
    }

    bottone->rect = option.rect.adjusted(4, 4, -(option.rect.width() / 2 + 4) , -4);
    painter->save();

    if (option.state & QStyle::State_Selected) {
        painter->fillRect(option.rect, option.palette.highlight());
    }

    painter->restore();
    QApplication::style()->drawControl(QStyle::CE_PushButton, bottone, painter);
}

bool DelegateAtleti::editorEvent(QEvent *event, QAbstractItemModel *model,
                                 const QStyleOptionViewItem &option, const QModelIndex &index)
{
    Q_UNUSED(option);
    Q_UNUSED(model);
    if(event->type() == QEvent::MouseButtonPress) {
        QMouseEvent* e = static_cast<QMouseEvent*>(event);
        if(btnEl.contains(index)) {
            QStyleOptionButton* btns = btnEl.value(index);
            if (btns->rect.contains(e->x(), e->y())) {
                btns->state |= QStyle::State_Sunken;
            }
        }
    }

    if (event->type() == QEvent::MouseButtonRelease) {
        QMouseEvent* e = static_cast<QMouseEvent*>(event);
        if (btnEl.contains(index)) {
            QStyleOptionButton* btns = btnEl.value(index);
            if (btns->rect.contains(e->x(), e->y())) {
                btns->state &= (~QStyle::State_Sunken);
                // avvisa che l'utente vuole eliminare la riga index.row()
                emit avvisoEliminazione(index.row());
            }
        }
    }
    return true;
}

void DelegateAtleti::slotEliminazione(int riga) {
    //rimuove un elemento corrispondente all'ultimo indice di riga da btnEl

    btnEl.

    emit eliminaRiga(riga);
}

#include "delegatebottone.h"
#include <QtGlobal>
#include <QDialog>
#include <QApplication>
#include <QAbstractItemModel>
#include <QEvent>
#include <QModelIndex>
#include <QStyleOptionViewItem>
#include <QMouseEvent>
#include <QPainter>
#include <QString>

DelegateBottone::DelegateBottone(QString titolo, QObject *parent)
    : QItemDelegate (parent), titoloBottone(titolo) {}

void DelegateBottone::paint(QPainter *painter, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const
{
    QStyleOptionButton* bottone = btnEl.value(index);
    if (!bottone) {
        bottone = new QStyleOptionButton();
        bottone->text = titoloBottone;
        bottone->state |= QStyle::State_Enabled;
        (const_cast<DelegateBottone *>(this))->btnEl.insert(index, bottone);
    }

    bottone->rect = option.rect.adjusted(4, 4, -(option.rect.width() / 2 + 4) , -4);
    painter->save();

    if (option.state & QStyle::State_Selected) {
        painter->fillRect(option.rect, option.palette.highlight());
    }

    painter->restore();
    QApplication::style()->drawControl(QStyle::CE_PushButton, bottone, painter);
}

bool DelegateBottone::editorEvent(
        QEvent *event, QAbstractItemModel *model,
        const QStyleOptionViewItem &option,
        const QModelIndex &index)
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

DelegateBottone::~DelegateBottone() {
    QMapIterator<QModelIndex, QStyleOptionButton*> i(btnEl);
    while (i.hasNext()) {
        i.next();
        delete i.value();
    }
}


#include "delegateatleti.h"
#include <QtGlobal>
#include <QDialog>
#include <QApplication>
#include <QAbstractItemModel>
#include <QEvent>
#include <QModelIndex>
#include <QStyleOptionViewItem>
#include <QMouseEvent>

// https://stackoverflow.com/questions/11777637/adding-button-to-qtableview
DelegateAtleti::DelegateAtleti(QObject *parent) : QItemDelegate (parent)
{
}

void DelegateAtleti::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    QStyleOptionButton bottone;
    QRect r = option.rect;//getting the rect of the cell
    int x,y,w,h;
    x = r.left() + r.width() - 30;//the X coordinate
    y = r.top();//the Y coordinate
    w = 30;//width del bottone
    h = 30;//height del bottone
    bottone.rect = QRect(x,y,w,h);
    bottone.text = "Elimina";
    bottone.state = QStyle::State_Enabled;

    QApplication::style()->drawControl( QStyle::CE_PushButton, &bottone, painter);
}

bool DelegateAtleti::editorEvent(QEvent *event, QAbstractItemModel *model,
                                 const QStyleOptionViewItem &option, const QModelIndex &index)
{
    Q_UNUSED(index);
    Q_UNUSED(model);

    if( event->type() == QEvent::MouseButtonRelease ) {
        QMouseEvent * e = static_cast<QMouseEvent *>(event);
        int clickX = e->x();
        int clickY = e->y();

        QRect r = option.rect;//getting the rect of the cell
        int x,y,w,h;
        x = r.left() + r.width() - 30;//the X coordinate
        y = r.top();//the Y coordinate
        w = 30;//button width
        h = 30;//button height

        if( clickX > x && clickX < x + w ) {
            if( clickY > y && clickY < y + h ) {
                QDialog * d = new QDialog();
                d->setGeometry(0,0,100,100);
                d->show();
            }
        }
    }

    return true;
}

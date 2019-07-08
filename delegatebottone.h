/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#ifndef DELEGATEBOTTONE_H
#define DELEGATEBOTTONE_H
#include <QItemDelegate>
#include <QAbstractItemModel>
#include <QEvent>
#include <QModelIndex>
#include <QStyleOptionViewItem>
#include <QList>
#include <QString>

class DelegateBottone : public QItemDelegate {
    Q_OBJECT
public:
    DelegateBottone(QString titolo, QObject *parent = nullptr);
    void paint(QPainter*, const QStyleOptionViewItem&, const QModelIndex&) const override;
    bool editorEvent(QEvent*, QAbstractItemModel*,
                     const QStyleOptionViewItem &, const QModelIndex &) override;
    ~DelegateBottone() override;
private:
    QString titoloBottone;
protected:
    typedef QMap<QModelIndex, QStyleOptionButton*> bottoniEliminazione; // per risparmiare anni di vita
    bottoniEliminazione btnEl;
signals:
    void avvisoPressioneBottone(int);
};

#endif // DELEGATEBOTTONE_H

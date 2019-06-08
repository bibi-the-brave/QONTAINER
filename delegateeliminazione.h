#ifndef DELEGATEATLETI_H
#define DELEGATEATLETI_H

#include <QItemDelegate>
#include <QAbstractItemModel>
#include <QEvent>
#include <QModelIndex>
#include <QStyleOptionViewItem>
#include <QList>

class DelegateEliminazione : public QItemDelegate
{
    Q_OBJECT
public:
    DelegateEliminazione(QObject *parent = nullptr);
    void paint(QPainter*, const QStyleOptionViewItem&, const QModelIndex&) const override;
    bool editorEvent(QEvent*, QAbstractItemModel*,
                     const QStyleOptionViewItem &, const QModelIndex &) override;
private:
    void visualizzaMessaggio(const QString&);

    typedef QMap<QModelIndex, QStyleOptionButton*> bottoniEliminazione; // per risparmiare anni di vita
    bottoniEliminazione btnEl;
signals:
    void avvisoEliminazione(int); // serve per avvisare che l'utente vuole eliminare una riga
    void eliminaRiga(int); // serve per far sapere al modello collegato che deve eliminare una riga
public slots:
    void slotEliminazione(int);
};

#endif // DELEGATEATLETI_H

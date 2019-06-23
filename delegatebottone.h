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
    virtual ~DelegateBottone() override; //non servirebbe marcarlo virtuale, lo è già quello di QObject
private:
    QString titoloBottone;
protected:
    void visualizzaMessaggio(const QString&);
    typedef QMap<QModelIndex, QStyleOptionButton*> bottoniEliminazione; // per risparmiare anni di vita
    bottoniEliminazione btnEl;
signals:
    void avvisoEliminazione(int); // serve per avvisare che l'utente vuole eliminare una riga
    void eliminaRiga(int); // serve per far sapere al modello collegato che deve eliminare una riga

};

#endif // DELEGATEBOTTONE_H

#ifndef DELEGATEELIMINAZIONE_H
#define DELEGATEELIMINAZIONE_H

#include "delegatebottone.h"

class DelegateEliminazione : public DelegateBottone {
    Q_OBJECT
public:
    DelegateEliminazione(QString = "Elimina", QObject* = nullptr);
public slots:
    void slotEliminazione(int);
signals:
    void avvisoEliminazione(int); // serve per avvisare che l'utente vuole eliminare una riga
    void eliminaRiga(int); // serve per far sapere al modello collegato che deve eliminare una riga
};

#endif // DELEGATEELIMINAZIONE_H

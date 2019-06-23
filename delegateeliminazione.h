#ifndef DELEGATEELIMINAZIONE_H
#define DELEGATEELIMINAZIONE_H

#include "delegatebottone.h"

class DelegateEliminazione : public DelegateBottone {
    Q_OBJECT
public:
    DelegateEliminazione(QString = "Elimina", QObject* = nullptr);
public slots:
    void slotEliminazione(int);
};

#endif // DELEGATEELIMINAZIONE_H

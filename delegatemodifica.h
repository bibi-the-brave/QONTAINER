/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#ifndef DELEGATEMODIFICA_H
#define DELEGATEMODIFICA_H

#include "delegatebottone.h"

class DelegateModifica : public DelegateBottone {
    Q_OBJECT
public:
    DelegateModifica(QString = "Modifica", QObject* = nullptr);
signals:
    void avvisoModifica(int);
};
#endif // DELEGATEMODIFICA_H

#ifndef DELEGATEMODIFICA_H
#define DELEGATEMODIFICA_H

#include "delegatebottone.h"

class DelegateModifica : public DelegateBottone {
    Q_OBJECT
public:
    DelegateModifica(QString = "Modifica", QObject* = nullptr);
public slots:
};
#endif // DELEGATEMODIFICA_H

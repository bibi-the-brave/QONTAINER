#include "delegateeliminazione.h"

DelegateEliminazione::DelegateEliminazione(QString strBottone, QObject* parent)
    : DelegateBottone (strBottone, parent)
{
}

void DelegateEliminazione::slotEliminazione(int riga) {
    //rimuove un elemento corrispondente all'ultimo indice di riga da btnEl
    btnEl.remove(btnEl.key(btnEl.last()));
    //emette un segnale per far eliminare la riga dalla tabella
    emit eliminaRiga(riga);
}

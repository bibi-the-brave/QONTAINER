/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#include "delegateeliminazione.h"

DelegateEliminazione::DelegateEliminazione(QString strBottone, QObject* parent)
    : DelegateBottone (strBottone, parent)
{
    connect(this, SIGNAL(avvisoPressioneBottone(int)), this, SIGNAL(avvisoEliminazione(int)));
}

void DelegateEliminazione::slotEliminazione(int riga) {
    //rimuove un elemento corrispondente all'ultimo indice di riga da btnEl
    btnEl.remove(btnEl.key(btnEl.last()));
    //emette un segnale per far eliminare la riga dalla tabella
    emit eliminaRiga(riga);
}

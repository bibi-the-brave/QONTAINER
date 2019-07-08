/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#include "delegatemodifica.h"

DelegateModifica::DelegateModifica(QString strBottone, QObject* parent)
    : DelegateBottone (strBottone, parent)
{
    connect(this, SIGNAL(avvisoPressioneBottone(int)), this, SIGNAL(avvisoModifica(int)));
}

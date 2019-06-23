#include "delegatemodifica.h"

DelegateModifica::DelegateModifica(QString strBottone, QObject* parent)
    : DelegateBottone (strBottone, parent)
{
    connect(this, SIGNAL(avvisoPressioneBottone(int)), this, SIGNAL(avvisoModifica(int)));
}

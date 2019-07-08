/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#include "sortfilterproxymodelallenamenti.h"
#include "allenamento.h"
#include "nuoto.h"
#include "ciclismo.h"
#include "corsa.h"
#include "triathlon.h"

SortFilterProxyModelAllenamenti::SortFilterProxyModelAllenamenti(Contenitore<DeepPtr<Allenamento>>& ca_,QObject* p)
    : QSortFilterProxyModel(p), ca(ca_), minore(nullptr), maggiore(nullptr)
{}

SortFilterProxyModelAllenamenti::~SortFilterProxyModelAllenamenti() {
    if(minore)
        delete minore;
    if(maggiore)
        delete  maggiore;
}


bool SortFilterProxyModelAllenamenti::filterAcceptsRow(int sourceRow,
                                                       const QModelIndex &sourceParent) const
{
    Q_UNUSED(sourceParent);
    if(!minore || !maggiore)
        return false;

    Allenamento *a = ca.At(sourceRow).get();
    if(!tipoRicerca) {
        return a->Allenamento::operator>=(*minore) && a->Allenamento::operator<=(*maggiore);
    } else {
        return *a >= *minore && *a <= *maggiore;
    }
}

bool SortFilterProxyModelAllenamenti::removeRows(int position, int rows, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), position, position+rows-1);
    // elimina righe dai dati sottostanti
    endRemoveRows();
    return true;
}

void SortFilterProxyModelAllenamenti::setTipoSort(int tr) {
    tipoRicerca = tr;
}

void SortFilterProxyModelAllenamenti::setAllenamentoMinore(Allenamento* aMin) {
    if(minore)
        delete minore;
    minore = aMin;
}

void SortFilterProxyModelAllenamenti::setAllenamentoMaggiore(Allenamento* aMax) {
    if(maggiore)
        delete maggiore;
    maggiore = aMax;
}

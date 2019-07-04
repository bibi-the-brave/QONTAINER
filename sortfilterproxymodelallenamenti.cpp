#include "sortfilterproxymodelallenamenti.h"
#include "allenamento.h"
#include "nuoto.h"
#include "ciclismo.h"
#include "corsa.h"
#include "triathlon.h"

SortFilterProxyModelAllenamenti::SortFilterProxyModelAllenamenti(Contenitore<DeepPtr<Allenamento>>& ca_,QObject* p)
    : QSortFilterProxyModel(p), ca(ca_), minore(nullptr), maggiore(nullptr)
{

}

bool SortFilterProxyModelAllenamenti::lessThan(const QModelIndex &left,
                                               const QModelIndex &right) const
{
return true;
}

bool SortFilterProxyModelAllenamenti::filterAcceptsRow(int sourceRow,
                                                       const QModelIndex &sourceParent) const
{

    return true;
}

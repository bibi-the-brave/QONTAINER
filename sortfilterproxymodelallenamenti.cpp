#include "sortfilterproxymodelallenamenti.h"

SortFilterProxyModelAllenamenti::SortFilterProxyModelAllenamenti(Contenitore<DeepPtr<Allenamento>>& ca_,QObject* p)
    : QSortFilterProxyModel(p), ca(ca_)
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

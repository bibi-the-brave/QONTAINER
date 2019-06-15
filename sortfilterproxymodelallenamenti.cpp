#include "sortfilterproxymodelallenamenti.h"

SortFilterProxyModelAllenamenti::SortFilterProxyModelAllenamenti(QObject *parent)
    : QSortFilterProxyModel(parent)
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

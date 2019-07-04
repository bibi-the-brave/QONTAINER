#ifndef SORTFILTERPROXYMODELALLENAMENTI_H
#define SORTFILTERPROXYMODELALLENAMENTI_H

#include <QModelIndex>
#include <QSortFilterProxyModel>
#include "allenamento.h"
#include "contenitore.h"
#include "deepptr.h"

class SortFilterProxyModelAllenamenti : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    SortFilterProxyModelAllenamenti(Contenitore<DeepPtr<Allenamento>>& ca,QObject* = nullptr);
protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;

private:
    Contenitore<DeepPtr<Allenamento>>& ca;
    enum {tutti, nuoto, ciclismo, corsa, triathlon};
    Allenamento* minore;
    Allenamento* maggiore;
};

#endif // SORTFILTERPROXYMODELALLENAMENTI_H

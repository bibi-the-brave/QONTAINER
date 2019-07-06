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
    ~SortFilterProxyModelAllenamenti() override;
protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:
    Contenitore<DeepPtr<Allenamento>>& ca;
    Allenamento* minore;
    Allenamento* maggiore;
    int tipoRicerca;
public slots:
    void setTipoSort(int);
    void setAllenamentoMinore(Allenamento*);
    void setAllenamentoMaggiore(Allenamento*);
};

#endif // SORTFILTERPROXYMODELALLENAMENTI_H

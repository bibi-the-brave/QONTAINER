#ifndef MODELTABELLAALLENAMENTI_H
#define MODELTABELLAALLENAMENTI_H

#include <memory>
#include <QAbstractTableModel>
#include "contenitore.h"
#include "persona.h"
#include "allenamento.h"
#include "deepptr.h"

class ModelTabellaAllenamenti : public QAbstractTableModel {
    Q_OBJECT
public:
    ModelTabellaAllenamenti(Contenitore<DeepPtr<Allenamento>>&, QObject* = nullptr);
    int rowCount(const QModelIndex& = QModelIndex()) const override;
    int columnCount(const QModelIndex& = QModelIndex()) const override;
    QVariant data(const QModelIndex&, int = Qt::DisplayRole) const override;
    QVariant headerData(int, Qt::Orientation, int) const override;
    bool removeRows(int, int, const QModelIndex &) override;
    bool insertRows(int, int, const QModelIndex &) override;

private:
    Contenitore<DeepPtr<Allenamento>>& dati;
};


#endif // MODELTABELLAALLENAMENTI_H

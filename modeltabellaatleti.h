#ifndef MODELTABELLAATLETI_H
#define MODELTABELLAATLETI_H

#include <memory>
#include <QAbstractTableModel>
#include "contenitore.h"
#include "persona.h"

class ModelTabellaAtleti : public  QAbstractTableModel {
    Q_OBJECT
public:
    ModelTabellaAtleti(Contenitore<std::shared_ptr<Persona>>&, QObject *parent = nullptr);
    int rowCount(const QModelIndex& = QModelIndex()) const override;
    int columnCount(const QModelIndex& = QModelIndex()) const override;
    QVariant data(const QModelIndex&, int = Qt::DisplayRole) const override;
    QVariant headerData(int, Qt::Orientation, int) const override;
private:
    Contenitore<std::shared_ptr<Persona>>& dati;
};

#endif // MODELTABELLAATLETI_H

#ifndef MODELTABELLAATLETI_H
#define MODELTABELLAATLETI_H

#include <QAbstractTableModel>

class ModelTabellaAtleti : public  QAbstractTableModel {
    Q_OBJECT
public:
    ModelTabellaAtleti(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // MODELTABELLAATLETI_H

#include "modeltabellaatleti.h"
#include <QtGlobal>

ModelTabellaAtleti::ModelTabellaAtleti(QObject *parent) : QAbstractTableModel(parent)
{

}

int ModelTabellaAtleti::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return -1; //da sistemare, valore fittizio
}

int ModelTabellaAtleti::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 3;   //nome, cognome, sesso
}


QVariant ModelTabellaAtleti::data(const QModelIndex &index, int role) const {
    return QVariant();
}

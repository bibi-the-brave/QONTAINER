#include "modeltabellaatleti.h"
#include <QtGlobal>
#include <QString>

ModelTabellaAtleti::ModelTabellaAtleti(Contenitore<std::shared_ptr<Persona>>& c, QObject *parent)
    : QAbstractTableModel(parent), dati(c)
{}

int ModelTabellaAtleti::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return static_cast<int>(dati.Size());
}

int ModelTabellaAtleti::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 4;   //nome, cognome, sesso, eliminazione (delegato)
}

QVariant ModelTabellaAtleti::data(const QModelIndex &index, int role) const {
    int riga = index.row();
    int colonna = index.column();

    switch (role) {
    case Qt::DisplayRole:
        switch (colonna) {
        case 0:
            return QString::fromStdString( (dati.At(riga))->getNome() );
        case 1:
            return QString::fromStdString( dati.At(riga)->getCognome() );
        case 2:
            return QString::fromStdString( dati.At(riga)->getSessoStr() );
        }
    }

    return QVariant();
}

QVariant ModelTabellaAtleti::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Nome");
        case 1:
            return QString("Cognome");
        case 2:
            return QString("Sesso");
        case 3:
            return QString("Eliminazione");
        }
    }
    return QVariant();
}

bool ModelTabellaAtleti::removeRows(int position, int rows, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), position, position+rows-1);
    // elimina righe dai dati sottostanti
    endRemoveRows();
    return true;
}

bool ModelTabellaAtleti::insertRows(int position, int rows, const QModelIndex &parent) {
    Q_UNUSED(parent);
    beginInsertRows(QModelIndex(), position, position+rows-1);
    // inserisce nuove righe nei dati sottostanti
    endInsertRows();
    return true;
}

/*Da chiamare quando viene aggiunto un nuovo atleta*/
void ModelTabellaAtleti::inserimentoNuovoAtletaEsterno() {
    beginResetModel();
        insertRow(rowCount());
    endResetModel();
}

void ModelTabellaAtleti::eliminazioneAtleta(int riga) {
    if(riga >= 0 && riga < columnCount()) {
        dati.removeAt(static_cast<unsigned int>(riga));
        removeRow(riga);
    }
}

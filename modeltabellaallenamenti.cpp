#include "modeltabellaallenamenti.h"
#include <QtGlobal>
#include <QString>

ModelTabellaAllenamenti::ModelTabellaAllenamenti(Contenitore<DeepPtr<Allenamento*>>& dati_, QObject *parent)
    : QAbstractTableModel(parent), dati(dati_)
{}

int ModelTabellaAllenamenti::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return static_cast<int>(dati.Size());
}

int ModelTabellaAllenamenti::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 7;   //Atleta, durata, magnesio, calorie, grasso perso, sali cosumat, elimina(delegato)
}

QVariant ModelTabellaAllenamenti::data(const QModelIndex &index, int role) const {
    int riga = index.row();
    int colonna = index.column();
/*
    switch (role) {
    case Qt::DisplayRole:
        switch (colonna) {
        case 0:
            return QString::fromStdString( dati.At(riga));
        case 1:
            return QString::fromStdString( dati.At(riga)->getCognome() );
        case 2:
            return QString::fromStdString( dati.At(riga)->getSessoStr() );
        }
    }*/

    return QVariant();
}

QVariant ModelTabellaAllenamenti::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Atleta");
        case 1:
            return QString("Durata");
        case 2:
            return QString("Magnesio");
        case 3:
            return QString("Consumo cal.");
        case 4:
            return QString("Grasso perso");
        case 5:
            return QString("Sali Consumati");
        case 6: //questo dopo diventa case 7 perché prima ci va qualità dell'allenamento da implementare
            return QString("Eliminazione");
        }
    }
    return QVariant();
}

bool ModelTabellaAllenamenti::removeRows(int position, int rows, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), position, position+rows-1);
    // elimina righe dai dati sottostanti
    endRemoveRows();
    return true;
}

bool ModelTabellaAllenamenti::insertRows(int position, int rows, const QModelIndex &parent) {
    Q_UNUSED(parent);
    beginInsertRows(QModelIndex(), position, position+rows-1);
    // inserisce nuove righe nei dati sottostanti
    endInsertRows();
    return true;
}


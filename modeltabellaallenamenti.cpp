#include "modeltabellaallenamenti.h"
#include <QtGlobal>
#include <QString>
#include "persona.h"
#include "allenamento.h"

ModelTabellaAllenamenti::ModelTabellaAllenamenti(Contenitore<DeepPtr<Allenamento>>& dati_, QObject *parent)
    : QAbstractTableModel(parent), dati(dati_)
{}

int ModelTabellaAllenamenti::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return static_cast<int>(dati.Size());
}

int ModelTabellaAllenamenti::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    // 0) Atleta, 1) Data 2) Allenamento, 3) durata, 4) magnesio, 5) calorie,
    // 6) grasso perso, 7) sali cosumati, 8) elimina (delegato), 9) modifica (delegato)
    return 10;
}

QVariant ModelTabellaAllenamenti::data(const QModelIndex &index, int role) const {
    int riga = index.row();
    int colonna = index.column();

    switch (role) {
    case Qt::DisplayRole:
        switch (colonna) {
        case 0:
            if( !dati.At(riga)->getAtleta().getSesso() ) {
                return QString::fromStdString( dati.At(riga)->getAtleta().getNome())
                    + " " + QString::fromStdString( dati.At(riga)->getAtleta().getCognome()) + " " + QString::fromUtf8("\u2642");
            } else {
                return QString::fromStdString( dati.At(riga)->getAtleta().getNome())
                    + " " + QString::fromStdString( dati.At(riga)->getAtleta().getCognome()) + " " + QString::fromUtf8("\u2640");
            }
        case 1:
            return QString::fromStdString( dati.At(riga)->getData().toString());
        case 2:
            return QString::fromStdString( dati.At(riga)->tipo() );
        case 3:
            return QString::fromStdString( std::to_string( dati.At(riga)->getDurata() ) ) + " min";
        case 4:
            return QString::fromStdString( std::to_string( dati.At(riga)->getMgMagnesioAssunti() ) )
                    + " mg";
        case 5:
            return QString::fromStdString( std::to_string( dati.At(riga)->calorie() )) + " cal";
        case 6:
            return QString::fromStdString( std::to_string( dati.At(riga)->grassoPerso() )) + " g";
        case 7:
            return QString::fromStdString( std::to_string( dati.At(riga)->saliMinerali() )) + " mg";
        }
    }

    return QVariant();
}

QVariant ModelTabellaAllenamenti::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Atleta");
        case 1:
            return QString("Data");
        case 2:
            return QString("Allenamento");
        case 3:
            return QString("Durata");
        case 4:
            return QString("Magnesio");
        case 5:
            return QString("Calorie");
        case 6:
            return QString("Dimagrimento");
        case 7:
            return QString("Sali Consumati");
        case 8:
            return QString("Eliminazione");
        case 9:
            return QString("Modifica");
        }
    }
    return QVariant();
}

//viene chiamato da removeRow
bool ModelTabellaAllenamenti::removeRows(int position, int rows, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), position, position+rows-1);
    // elimina righe dai dati sottostanti
    endRemoveRows();
    return true;
}

//viene chiamato da insertRow
bool ModelTabellaAllenamenti::insertRows(int position, int rows, const QModelIndex &parent) {
    Q_UNUSED(parent);
    beginInsertRows(QModelIndex(), position, position+rows-1);
    // inserisce nuove righe nei dati sottostanti
    endInsertRows();
    return true;
}

void ModelTabellaAllenamenti::inserimentoNuovoAllenamentoEsterno() {
    beginResetModel();
        insertRow(rowCount());
    endResetModel();
}

void ModelTabellaAllenamenti::eliminazioneAllenamento(int riga) {
    if(riga >= 0 && riga < rowCount()) {
        dati.removeAt(static_cast<unsigned int>(riga));
        removeRow(riga);
    }
}

void ModelTabellaAllenamenti::eliminazioneAllenamenti(std::shared_ptr<Persona> atleta) {
    Contenitore<DeepPtr<Allenamento>>::iterator it = dati.begin();
    for(int i = 0; it != dati.end();  ++i) {
        if( (*it)->getAtleta() == *atleta ) {
            it = dati.erase(it);
            removeRow(i);
            --i;
        } else
            ++it;
    }
}

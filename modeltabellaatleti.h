/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
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
    bool removeRows(int, int, const QModelIndex &) override;
    bool insertRows(int, int, const QModelIndex &) override;
public slots:
    void inserimentoNuovoAtletaEsterno();
    void eliminazioneAtleta(int);
private:
    Contenitore<std::shared_ptr<Persona>>& dati;
signals:
    void atletaDaEliminare(std::shared_ptr<Persona>);
};

#endif // MODELTABELLAATLETI_H

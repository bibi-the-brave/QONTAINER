#ifndef FINESTRAATLETI_H
#define FINESTRAATLETI_H

#include <QWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <memory>

#include "contenitore.h"
#include "persona.h"
#include "allenamento.h"
#include "deepptr.h"
#include "modeltabellaatleti.h"
#include "delegateatleti.h"

class FinestraAtleti : public QWidget {
    Q_OBJECT
public:
    explicit FinestraAtleti(Contenitore<std::shared_ptr<Persona>>&,QWidget *parent = nullptr);

private:
    QVBoxLayout layout;
    QPushButton btnNuovoAtleta;
    QLabel lblTitolo;
    QTableView tabAtleti;

    Contenitore<std::shared_ptr<Persona>>& atleti;
    ModelTabellaAtleti modello;
    DelegateAtleti delegato;
public slots:
    void avviaDialogInserimento(bool);
    void ricevutaNotificaEliminazioneRiga(int);
signals:
    void rimuovereRiga(int);
};

#endif // FINESTRAATLETI_H

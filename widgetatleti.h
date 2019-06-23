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
#include "modeltabellaatleti.h"
#include "delegateeliminazione.h"
#include "delegatemodifica.h"

class WidgetAtleti : public QWidget {
    Q_OBJECT
public:
    explicit WidgetAtleti(Contenitore<std::shared_ptr<Persona>>&,QWidget* = nullptr);

private:
    QVBoxLayout *layout;
    QPushButton *btnNuovoAtleta;
    QLabel *lblTitolo;
    QTableView *tabAtleti;

    Contenitore<std::shared_ptr<Persona>>& atleti;
    ModelTabellaAtleti *modello;
    DelegateEliminazione *delegatoEl;
    DelegateModifica *delegatoMod;
public slots:
    void avviaDialogInserimento(bool);
    void ricevutaNotificaEliminazioneRiga(int);
    void avviaDialogModifica(int);
signals:
    void rimuovereRiga(int);
};

#endif // FINESTRAATLETI_H

#include "finestraatleti.h"

#include <QStringList>
#include "dialoginserimentoatleta.h"

FinestraAtleti::FinestraAtleti(QWidget *parent) : QWidget(parent)
{
    QStringList header;
    header << "Nome" << "Cognome" << "Elimina";

    //tabAtleti.setHorizontalHeader(header);
    lblTitolo.setText("ATLETI");
    btnNuovoAtleta.setText("Nuovo Atleta");

    layout.addWidget(&lblTitolo);
    layout.setAlignment(&lblTitolo, Qt::AlignHCenter);
    layout.addWidget(&tabAtleti);
    layout.addWidget(&btnNuovoAtleta);
    layout.setAlignment(&btnNuovoAtleta, Qt::AlignHCenter);

    setLayout(&layout);

    connect(&btnNuovoAtleta, SIGNAL(clicked(bool)), this, SLOT(avviaDialogInserimento(bool)));
}


void FinestraAtleti::avviaDialogInserimento(bool cliccato) {
    DialogInserimentoAtleta da;
    da.exec();
}

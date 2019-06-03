#include "finestraatleti.h"

#include <QStringList>

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
}

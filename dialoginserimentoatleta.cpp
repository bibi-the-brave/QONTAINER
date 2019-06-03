#include "dialoginserimentoatleta.h"
#include <QtGlobal>

DialogInserimentoAtleta::DialogInserimentoAtleta(QWidget* parent) : QDialog(parent)
{
    lblTitolo.setText("INSERIMENTO NUOVA/O ATLETA");
    lblNome.setText("Nome");
    lblCognome.setText("Cognome");
    bInserisci.setText("Inserisci");
    bAzzera.setText("Reset");

    layoutPrincipale.addWidget(&lblTitolo);
    layoutPrincipale.setAlignment(&lblTitolo, Qt::AlignHCenter);

    layoutForm.addRow(&lblNome, &leNome);
    layoutForm.addRow(&lblCognome, &leCognome);

    layoutBottoniConferma.addWidget(&bInserisci);
    layoutBottoniConferma.addWidget(&bAzzera);

    layoutPrincipale.addLayout(&layoutForm);
    layoutPrincipale.addLayout(&layoutBottoniConferma);
    setLayout(&layoutPrincipale);

    connect(&bInserisci, SIGNAL(clicked(bool)), this, SLOT(inserimento(bool)));
    connect(&bAzzera, SIGNAL(clicked(bool)), this, SLOT(azzeramentoForm(bool)));
}

void DialogInserimentoAtleta::inserimentoAtleta(bool cliccato) {
    Q_UNUSED(cliccato);
}

void DialogInserimentoAtleta::azzeramentoForm(bool cliccato) {
    Q_UNUSED(cliccato);
    leNome.setText("");
    leCognome.setText("");
}

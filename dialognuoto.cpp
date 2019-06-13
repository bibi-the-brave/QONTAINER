#include "dialognuoto.h"
#include <QMessageBox>

DialogNuoto::DialogNuoto(
        Contenitore<std::shared_ptr<Persona>>& cp_,
        Contenitore<DeepPtr<Allenamento>>& ca_,
        QWidget* parent)
    : DialogAllenamento(cp_,ca_,parent)
{
    wNuoto = new WidgetNuoto();
    layoutPrincipale->addWidget(wNuoto);
    aggiungiBottoni();

    connect(bReset, SIGNAL(clicked()), wNuoto, SLOT(reset()));
    connect(bReset, SIGNAL(clicked()), this, SLOT(reset()));
}

void DialogNuoto::setLabelTitolo() {
    lblTitolo->setText("ALLENAMENTO NUOTO");
}


void DialogNuoto::dialogErroreForm() const {
    QMessageBox mes;
    mes.setIcon(QMessageBox::Information);
    mes.setText("Errore!");
    mes.setInformativeText("È necessario aver fatto almeno una vasca in uno dei tre stili.");
    mes.setStandardButtons(QMessageBox::Ok);
    mes.exec();
}

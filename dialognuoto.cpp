#include "dialognuoto.h"
#include "nuoto.h"
#include <string>

DialogNuoto::DialogNuoto(
        Contenitore<std::shared_ptr<Persona>>& cp_,
        Contenitore<DeepPtr<Allenamento>>& ca_,
        QWidget* parent)
    : DialogAllenamento(cp_,ca_,parent)
{
    wNuoto = new WidgetNuoto();
    layoutPrincipale->addWidget(wNuoto);
    aggiungiBottoni();
    setWindowTitle("NUOTO");

    connect(bReset, SIGNAL(clicked()), wNuoto, SLOT(reset()));
    connect(bReset, SIGNAL(clicked()), this, SLOT(reset()));
    connect(bConferma, SIGNAL(clicked()), this, SLOT(inserimentoAllenamento()));
}

void DialogNuoto::setLabelTitolo() {
    lblTitolo->setText("ALLENAMENTO NUOTO");
}

void DialogNuoto::inserimentoAllenamento() {
    bool erroriCompilazione;
    controlloForm(erroriCompilazione);
    if(erroriCompilazione) {
        dialogErroreForm();
        return;
    }

    wNuoto->controlloForm(erroriCompilazione);
    if(erroriCompilazione) {
        wNuoto->dialogErroreForm();
        return;
    }

    std::string strData = deData->date().toString("dd/MM/yyyy").toStdString();
    Allenamento* al = new Nuoto(cp.At(cmbAtleti->currentIndex()),
                                static_cast<unsigned int>(spinDurata->value()),
                                Data(strData),
                                spinMagnesio->value(),
                                static_cast<unsigned int>(wNuoto->vascheLibero()),
                                static_cast<unsigned int>(wNuoto->vascheRana()),
                                static_cast<unsigned int>(wNuoto->vascheDorso()));

    if(ca.elementoPresente(al)) {
        dialogErroreDoppione();
        return;
    }

    ca.pushBack(DeepPtr<Allenamento>(al));
    emit aggiungereAllenamento();
    delete al; //DeepPtr costruisce di copia i suoi elementi
    close();
}

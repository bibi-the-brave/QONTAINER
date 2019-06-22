#include "dialogtriathlon.h"
#include "corsa.h"
#include "nuoto.h"
#include "ciclismo.h"
#include "deepptr.h"
#include "triathlon.h"

DialogTriathlon::DialogTriathlon(Contenitore<std::shared_ptr<Persona>>& cp_,
                                 Contenitore<DeepPtr<Allenamento>>& ca_,
                                 QWidget* parent)
    : DialogAllenamento(cp_,ca_,parent)
{

    wNuoto = new WidgetNuoto();
    layoutPrincipale->addWidget(wNuoto);
    wCorsa = new WidgetCorsa();
    layoutPrincipale->addWidget(wCorsa);
    wCiclismo = new WidgetCiclismo();
    layoutPrincipale->addWidget(wCiclismo);
    aggiungiBottoni();
    setWindowTitle("TRIATHLON");

    connect(bReset, SIGNAL(clicked()), wNuoto, SLOT(reset()));
    connect(bReset, SIGNAL(clicked()), wCorsa, SLOT(reset()));
    connect(bReset, SIGNAL(clicked()), wCiclismo, SLOT(reset()));
    connect(bReset, SIGNAL(clicked()), this, SLOT(reset()));
    connect(bConferma, SIGNAL(clicked()), this, SLOT(inserimentoAllenamento()));
}

void DialogTriathlon::setLabelTitolo() {
    lblTitolo->setText("ALLENAMENTO TRIATHLON");
}


void DialogTriathlon::inserimentoAllenamento() {
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

    wCiclismo->controlloForm(erroriCompilazione);
    if(erroriCompilazione) {
        wCiclismo->dialogErroreForm();
        return;
    }

    wCorsa->controlloForm(erroriCompilazione);
    if(erroriCompilazione) {
        wCorsa->dialogErroreForm();
        return;
    }

    std::string strData = deData->date().toString("dd/MM/yyyy").toStdString();
    Allenamento* al = new Triathlon(cp.At(cmbAtleti->currentIndex()),
                                    static_cast<unsigned int>(spinDurata->value()),
                                    Data(strData),
                                    spinMagnesio->value(),
                                    static_cast<unsigned int>(wNuoto->vascheLibero()),
                                    static_cast<unsigned int>(wNuoto->vascheRana()),
                                    static_cast<unsigned int>(wNuoto->vascheDorso()),
                                    static_cast<unsigned int>(wCorsa->kmSterrato()),
                                    static_cast<unsigned int>(wCorsa->kmStrada()),
                                    static_cast<unsigned int>(wCiclismo->kmSalita()),
                                    static_cast<unsigned int>(wCiclismo->kmPianura()),
                                    static_cast<unsigned int>(wCiclismo->kmDiscesa()));
    if(ca.elementoPresente(al)) {
        dialogErroreDoppione();
        return;
    }

    ca.pushBack(DeepPtr<Allenamento>(al));
    emit aggiungereAllenamento();
    delete al; //DeepPtr costruisce di copia i suoi elementi
    close();
}


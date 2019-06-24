#include "dialogtriathlon.h"
#include "corsa.h"
#include "nuoto.h"
#include "ciclismo.h"
#include "deepptr.h"
#include "triathlon.h"

DialogTriathlon::DialogTriathlon(Contenitore<std::shared_ptr<Persona>>& cp_,
                                 Contenitore<DeepPtr<Allenamento>>& ca_,
                                 bool modifica,
                                 int rigaMod,
                                 QWidget* parent)
    : DialogAllenamento(cp_,ca_,modifica, rigaMod,parent)
{

    wNuoto = new WidgetNuoto();
    layoutPrincipale->addWidget(wNuoto);
    wCorsa = new WidgetCorsa();
    layoutPrincipale->addWidget(wCorsa);
    wCiclismo = new WidgetCiclismo();
    layoutPrincipale->addWidget(wCiclismo);
    aggiungiBottoni();
    setWindowTitle("TRIATHLON");
    setLabelTitolo();

    connect(bReset, SIGNAL(clicked()), wNuoto, SLOT(reset()));
    connect(bReset, SIGNAL(clicked()), wCorsa, SLOT(reset()));
    connect(bReset, SIGNAL(clicked()), wCiclismo, SLOT(reset()));
    connect(bReset, SIGNAL(clicked()), this, SLOT(reset()));
    if(!modifica)
        connect(bConferma, SIGNAL(clicked()), this, SLOT(inserimentoAllenamento()));
    else {
        compilazioneFormModifica();
        connect(bConferma, SIGNAL(clicked()), this, SLOT(modificaAllenamento()));
    }
}

void DialogTriathlon::setLabelTitolo() {
    if(!modifica)
        lblTitolo->setText("NUOVO ALLENAMENTO TRIATHLON");
    else
        lblTitolo->setText("MODIFICA ALLENAMENTO TRIATHLON");
}

void DialogTriathlon::compilazioneFormModifica() {
    Triathlon* a = dynamic_cast<Triathlon*>(ca.At(rigaMod).get());
    if(!a)
        return;
    int i = cmbAtleti->findText(
                QString::fromStdString(a->getAtleta().getNome() + " "
                                       + a->getAtleta().getCognome())
    );
    cmbAtleti->setCurrentIndex(i);

    QDate data(a->getData().getY(), a->getData().getM(), a->getData().getD());
    deData->setDate(data);

    spinDurata->setValue(static_cast<int>(a->getDurata()));
    spinMagnesio->setValue(static_cast<int>(a->getMgMagnesioAssunti()));
    //nuoto
    wNuoto->setVascheLibero(static_cast<int>(a->getVascheStileLibero()));
    wNuoto->setVascheDorso(static_cast<int>(a->getVascheDorso()));
    wNuoto->setVascheRana(static_cast<int>(a->getVascheRana()));
    //ciclismo
    wCiclismo->setKmSalita(static_cast<int>(a->getKmSalita()));
    wCiclismo->setKmDiscesa(static_cast<int>(a->getKmDiscesa()));
    wCiclismo->setKmPianura(static_cast<int>(a->getKmPianura()));
    //corsa
    wCorsa->setKmStrada(static_cast<int>(a->getKmStrada()));
    wCorsa->setKmSterrato(static_cast<int>(a->getKmSterrato()));
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

void DialogTriathlon::modificaAllenamento() {
    Triathlon* allenamentoSelezionato = dynamic_cast<Triathlon*>(ca.At(rigaMod).get());
    if(!allenamentoSelezionato)
        return;

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

    if(*allenamentoSelezionato == *al) {
        visualizzaMessaggioAllenamentoNonModificato();
        this->close();
        return; //lo metto perché è capitato che prima di eseguire close venga eseguita
        //la parte in cui si controlla doppione. Penso perché close possa essere multithread
    }


    if(ca.elementoPresente(al)) {
        dialogErroreDoppione();
        return;
    } else { // modifico l'atleta. Il model e la view si aggiornano in automatico
        allenamentoSelezionato->setData(al->getData());
        allenamentoSelezionato->setDurata(al->getDurata());
        allenamentoSelezionato->setMgMagnesio(al->getMgMagnesioAssunti());
        // nuoto
        allenamentoSelezionato->setVascheRana(dynamic_cast<Nuoto*>(al)->getVascheRana());
        allenamentoSelezionato->setVascheStileLibero(dynamic_cast<Nuoto*>(al)->getVascheStileLibero());
        allenamentoSelezionato->setVascheDorso(dynamic_cast<Nuoto*>(al)->getVascheDorso());
        // ciclismo
        allenamentoSelezionato->setKmPianura(dynamic_cast<Ciclismo*>(al)->getKmPianura());
        allenamentoSelezionato->setKmSalita(dynamic_cast<Ciclismo*>(al)->getKmSalita());
        allenamentoSelezionato->setKmDiscesa(dynamic_cast<Ciclismo*>(al)->getKmDiscesa());
        // corsa
        allenamentoSelezionato->setKmSterrato(dynamic_cast<Corsa*>(al)->getKmSterrato());
        allenamentoSelezionato->setKmStrada(dynamic_cast<Corsa*>(al)->getKmStrada());
        this->close();
    }
}

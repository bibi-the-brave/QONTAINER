#include "dialognuoto.h"
#include "allenamento.h"
#include "nuoto.h"
#include <string>


DialogNuoto::DialogNuoto(
        Contenitore<std::shared_ptr<Persona>>& cp_,
        Contenitore<DeepPtr<Allenamento>>& ca_,
        bool modifica,
        int rigaMod,
        QWidget* parent)
    : DialogAllenamento(cp_,ca_,modifica, rigaMod, parent)
{
    wNuoto = new WidgetNuoto();
    layoutPrincipale->addWidget(wNuoto);
    aggiungiBottoni();
    setWindowTitle("NUOTO");
    setLabelTitolo();

    connect(bReset, SIGNAL(clicked()), wNuoto, SLOT(reset()));
    connect(bReset, SIGNAL(clicked()), this, SLOT(reset()));
    if(!modifica)
        connect(bConferma, SIGNAL(clicked()), this, SLOT(inserimentoAllenamento()));
    else {
        compilazioneFormModifica();
        connect(bConferma, SIGNAL(clicked()), this, SLOT(modificaAllenamento()));
    }
}

void DialogNuoto::setLabelTitolo() {
    if(!modifica)
        lblTitolo->setText("NUOVO ALLENAMENTO NUOTO");
    else
        lblTitolo->setText("MODIFICA ALLENAMENTO NUOTO");
}

void DialogNuoto::compilazioneFormModifica() {
    Nuoto* a = dynamic_cast<Nuoto*>(ca.At(rigaMod).get());
    if(!a)
        return;

    wNuoto->setVascheLibero(static_cast<int>(a->getVascheStileLibero()));
    wNuoto->setVascheDorso(static_cast<int>(a->getVascheDorso()));
    wNuoto->setVascheRana(static_cast<int>(a->getVascheRana()));
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

void DialogNuoto::modificaAllenamento() {
    Nuoto* allenamentoSelezionato = dynamic_cast<Nuoto*>(ca.At(rigaMod).get());
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

    std::string strData = deData->date().toString("dd/MM/yyyy").toStdString();
    Allenamento* al = new Nuoto(cp.At(cmbAtleti->currentIndex()),
                                static_cast<unsigned int>(spinDurata->value()),
                                Data(strData),
                                spinMagnesio->value(),
                                static_cast<unsigned int>(wNuoto->vascheLibero()),
                                static_cast<unsigned int>(wNuoto->vascheRana()),
                                static_cast<unsigned int>(wNuoto->vascheDorso()));

    if(*allenamentoSelezionato == *al) {
        visualizzaMessaggioAllenamentoNonModificato();
        this->close();
        return; //lo metto perché è capitato che prima di eseguire close venga eseguita
        //la parte in cui si controlla doppione. Penso perché close possa essere multithread
    }


    if(ca.elementoPresente(al)) {
        dialogErroreDoppione();
        return;
    } else { //modifico l'atleta. Il model e la view si aggiornano in automatico
        allenamentoSelezionato->setData(al->getData());
        allenamentoSelezionato->setDurata(al->getDurata());
        allenamentoSelezionato->setMgMagnesio(al->getMgMagnesioAssunti());
        allenamentoSelezionato->setVascheRana(dynamic_cast<Nuoto*>(al)->getVascheRana());
        allenamentoSelezionato->setVascheStileLibero(dynamic_cast<Nuoto*>(al)->getVascheStileLibero());
        allenamentoSelezionato->setVascheDorso(dynamic_cast<Nuoto*>(al)->getVascheDorso());
        this->close();
    }

}

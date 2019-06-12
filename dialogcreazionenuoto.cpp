#include "dialogcreazionenuoto.h"

DialogCreazioneNuoto::DialogCreazioneNuoto(
        Contenitore<std::shared_ptr<Persona>>& cp_,
        Contenitore<DeepPtr<Allenamento>>& ca_,
        QWidget* parent)
    : DialogCreazioneAllenamento(cp_,ca_,parent)
{
    wNuoto = new WidgetNuoto();
    layoutPrincipale->addWidget(wNuoto);
    aggiungiBottoni();
}

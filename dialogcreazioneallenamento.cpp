#include "dialogcreazioneallenamento.h"

DialogCreazioneAllenamento::DialogCreazioneAllenamento(
        Contenitore<DeepPtr<Allenamento>>& ca_, QWidget* parent)
    : QDialog(parent), ca(ca_)
{
}



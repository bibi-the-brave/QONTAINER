#ifndef DIALOGCREAZIONENUOTO_H
#define DIALOGCREAZIONENUOTO_H

#include "dialogcreazioneallenamento.h"
#include <QGroupBox>
#include "widgetnuoto.h"

class DialogCreazioneNuoto : public DialogCreazioneAllenamento {
    Q_OBJECT
public:
    DialogCreazioneNuoto(Contenitore<std::shared_ptr<Persona>>&,
                         Contenitore<DeepPtr<Allenamento>>&,
                         QWidget* = nullptr);
private:
    QGroupBox *gbNuoto;
    WidgetNuoto *wNuoto;
};

#endif // DIALOGCREAZIONENUOTO_H

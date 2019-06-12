#ifndef DIALOGCORSA_H
#define DIALOGCORSA_H

#include "dialogallenamento.h"

class DialogCorsa : public DialogAllenamento {
    Q_OBJECT
public:
    DialogCorsa(Contenitore<std::shared_ptr<Persona>>&,
                         Contenitore<DeepPtr<Allenamento>>&,
                         QWidget* = nullptr);
};

#endif // DIALOGCORSA_H

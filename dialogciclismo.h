#ifndef DIALOGCICLISMO_H
#define DIALOGCICLISMO_H

#include "dialogallenamento.h"

class DialogCiclismo : public DialogAllenamento {
    Q_OBJECT
public:
    DialogCiclismo(Contenitore<std::shared_ptr<Persona>>&,
                         Contenitore<DeepPtr<Allenamento>>&,
                         QWidget* = nullptr);
};

#endif // DIALOGCICLISMO_H

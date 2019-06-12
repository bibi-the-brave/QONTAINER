#include "dialogtriathlon.h"

DialogTriathlon::DialogTriathlon(Contenitore<std::shared_ptr<Persona>>& cp_,
                                 Contenitore<DeepPtr<Allenamento>>& ca_,
                                 QWidget* parent)
    : DialogAllenamento(cp_,ca_,parent)
{

}

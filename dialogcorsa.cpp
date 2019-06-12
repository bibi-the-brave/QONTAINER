#include "dialogcorsa.h"

DialogCorsa::DialogCorsa(Contenitore<std::shared_ptr<Persona>>& cp_,
                         Contenitore<DeepPtr<Allenamento>>& ca_,
                         QWidget* parent)
                     : DialogAllenamento(cp_,ca_,parent)
{

}

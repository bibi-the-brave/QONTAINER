#ifndef FINESTRAPRINCIPALE_H
#define FINESTRAPRINCIPALE_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QTabWidget>
#include <QPushButton>
#include <memory>

#include "contenitore.h"
#include "persona.h"
#include "allenamento.h"
#include "deepptr.h"
#include "widgetatleti.h"
#include "widgetallenamenti.h"
#include "widgetricerca.h"

class FinestraPrincipale : public QMainWindow {
    Q_OBJECT
private:
    QWidget* centrale;
    QTabWidget* tabFunzionalita;
    WidgetAtleti* fa;
    WidgetAllenamenti* wa;
    WidgetRIcerca* wr;

    FinestraPrincipale(const FinestraPrincipale&) = delete;
    FinestraPrincipale& operator=(const FinestraPrincipale&) = delete;

    Contenitore<DeepPtr<Allenamento*>>& ca;
    Contenitore<std::shared_ptr<Persona>>& cp;
public:
    FinestraPrincipale(Contenitore<DeepPtr<Allenamento*>>&,
                       Contenitore<std::shared_ptr<Persona>>&,
                       QWidget *parent = nullptr);
};

#endif // FINESTRAPRINCIPALE_H

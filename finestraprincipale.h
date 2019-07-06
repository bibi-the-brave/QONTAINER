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
#include "widgetintroduttivo.h"
#include "widgetatleti.h"
#include "widgetallenamenti.h"
#include "widgetricerca.h"

class FinestraPrincipale : public QMainWindow {
    Q_OBJECT
public:
    FinestraPrincipale(Contenitore<DeepPtr<Allenamento>>&,
                       Contenitore<std::shared_ptr<Persona>>&,
                       QWidget *parent = nullptr);

    FinestraPrincipale(const FinestraPrincipale&) = delete;
    FinestraPrincipale& operator=(const FinestraPrincipale&) = delete;
    ~FinestraPrincipale();
private:
    QWidget* centrale;
    QTabWidget* tabFunzionalita;
    WidgetIntroduttivo *wi;
    WidgetAtleti* fa;
    WidgetAllenamenti* wa;
    WidgetRicerca* wr;

    Contenitore<DeepPtr<Allenamento>>& ca;
    Contenitore<std::shared_ptr<Persona>>& cp;
public slots:
    void impostaTab();
};

#endif // FINESTRAPRINCIPALE_H

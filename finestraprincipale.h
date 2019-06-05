#ifndef FINESTRAPRINCIPALE_H
#define FINESTRAPRINCIPALE_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include <memory>

#include "contenitore.h"
#include "persona.h"
#include "allenamento.h"
#include "deepptr.h"


class FinestraPrincipale : public QMainWindow {
    Q_OBJECT
private:
    QWidget* centrale;
    QHBoxLayout *layout;
    QPushButton *bInserAtleta, *bInserAllenamento, *bRicerca;

    Contenitore<DeepPtr<Allenamento*>>& ca;
    Contenitore<std::shared_ptr<Persona*>>& cp;
public:
    FinestraPrincipale(Contenitore<DeepPtr<Allenamento*>>&,
                       Contenitore<std::shared_ptr<Persona*>>&,
                       QWidget *parent = nullptr);
    ~FinestraPrincipale();
private slots:
    void aperturaAtleta(bool);
};

#endif // FINESTRAPRINCIPALE_H

#ifndef WIDGETNUOVOSPORT_H
#define WIDGETNUOVOSPORT_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <memory>
#include "contenitore.h"
#include "allenamento.h"
#include "deepptr.h"
#include "modeltabellaallenamenti.h"

class WidgetNuovoSport : public QWidget {
    Q_OBJECT
private:
    QLabel* lblCreazione;
    QVBoxLayout *layout;
    QHBoxLayout *layoutBottoni;
    QPushButton* creaBottoneSport(const QString&) ;

    Contenitore<std::shared_ptr<Persona>>& cp;
    Contenitore<DeepPtr<Allenamento>>& ca;
    ModelTabellaAllenamenti& m;
public:
    WidgetNuovoSport(Contenitore<std::shared_ptr<Persona>> &,
                     Contenitore<DeepPtr<Allenamento>> &,
                     ModelTabellaAllenamenti&,
                     QWidget* = nullptr);
signals:
    void sportSelezionato(QString);

private slots:
    void creaDialogInserimentoSport(QString);
};

#endif // WIDGETNUOVOSPORT_H

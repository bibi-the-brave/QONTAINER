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

class WidgetNuovoSport : public QWidget {
    Q_OBJECT
private:
    QLabel* lblCreazione;
    QVBoxLayout *layout;
    QHBoxLayout *layoutBottoni;
    QPushButton* creaBottoneSport(const QString&) ;

    Contenitore<std::shared_ptr<Persona>>& cp;
    Contenitore<DeepPtr<Allenamento>>& ca;
public:
    WidgetNuovoSport(Contenitore<std::shared_ptr<Persona>> &,
                     Contenitore<DeepPtr<Allenamento>> &,
                     QWidget* = nullptr);
signals:
    void sportSelezionato(QString);

private slots:
    void creaOggettoInserimentoSport(QString);
};

#endif // WIDGETNUOVOSPORT_H

#ifndef WIDGETALLENAMENTI_H
#define WIDGETALLENAMENTI_H

#include <QWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QLabel>

#include "contenitore.h"
#include "allenamento.h"
#include "deepptr.h"
#include "persona.h"
#include "deepptr.h"
#include "modeltabellaallenamenti.h"
#include "delegateeliminazione.h"
#include "delegatemodifica.h"
#include "widgetnuovosport.h"

class WidgetAllenamenti : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetAllenamenti(Contenitore<std::shared_ptr<Persona>>&,
                               Contenitore<DeepPtr<Allenamento>>&, QWidget* = nullptr);
    ModelTabellaAllenamenti* getModello() const;
private:
    QVBoxLayout* layout;
    QLabel* lblTitolo;
    QTableView* tabAllenamenti;
    WidgetNuovoSport* widgetCreazione;

    Contenitore<DeepPtr<Allenamento>>& ca;
    Contenitore<std::shared_ptr<Persona>>& catleti;
    ModelTabellaAllenamenti* modello;
    DelegateEliminazione* delegatoEl;
    DelegateModifica* delegatoMod;
public slots:
    void ricevutaNotificaEliminazioneRiga(int);
signals:
    void rimuovereRiga(int);
};

#endif // WIDGETALLENAMENTI_H

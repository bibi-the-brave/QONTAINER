#ifndef WIDGETALLENAMENTI_H
#define WIDGETALLENAMENTI_H

#include <QWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QLabel>

#include "contenitore.h"
#include "allenamento.h"
#include "deepptr.h"
#include "modeltabellaallenamenti.h"
#include "delegateeliminazione.h"
#include "widgetnuovosport.h"

class WidgetAllenamenti : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetAllenamenti(Contenitore<DeepPtr<Allenamento>>&, QWidget* = nullptr);
private:
    QVBoxLayout* layout;
    QLabel* lblTitolo;
    QTableView* tabAllenamenti;
    WidgetNuovoSport* widgetCreazione;

    Contenitore<DeepPtr<Allenamento>>& ca;
    ModelTabellaAllenamenti* modello;
    DelegateEliminazione* delegato;
public slots:
    void ricevutaNotificaEliminazioneRiga(int);
    void avviaFinestraInserimentoAllen(bool);
signals:
    void rimuovereRiga(int);
};

#endif // WIDGETALLENAMENTI_H

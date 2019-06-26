#ifndef WIDGETRICERCA_H
#define WIDGETRICERCA_H

#include <QWidget>
#include "contenitore.h"
#include "allenamento.h"
#include "deepptr.h"
#include <QGroupBox>
#include <QRadioButton>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QTableView>
#include <QDateEdit>
#include "widgetnuoto.h"
#include "widgetciclismo.h"
#include "widgetcorsa.h"
#include "modeltabellaallenamenti.h"
#include "delegateeliminazione.h"

class WidgetRicerca : public QWidget {
    Q_OBJECT
public:
    WidgetRicerca(Contenitore<DeepPtr<Allenamento>>&, QWidget* = nullptr);
private:
    Contenitore<DeepPtr<Allenamento>>& ca;

    QVBoxLayout *layoutPrincipale, *layoutComponentiRicerca;
    QHBoxLayout* layoutRadioSport; // layout per i radiobutton per selezionare lo sport
    QGridLayout* layoutBoxFormRicerca; // layout che contiene i form relativi agli sport
    QFormLayout *lPersona;
    QGroupBox *boxRicerca, *boxPersona;
    QPushButton *btnRicerca;
    QRadioButton *rbNuoto, *rbCorsa, *rbCiclismo, *rbTriathlon, *rbAtleta;

    // ricerca atleta
    QLabel *lblAtleti, *lblSesso, *lblMAgnesio, *lblDataInizio, *lblDataFine;
    QComboBox* cmbAtleti;
    QGroupBox* boxSesso;
    QHBoxLayout* lSesso;
    QRadioButton *rbUomo, *rbDonna;
    QDateEdit *deDataInizio, *deDatFine;

    WidgetNuoto* wNuoto;
    WidgetCorsa* wCorsa;
    WidgetCiclismo* wCiclismo;

    QTableView* tabellaRicerca;
    ModelTabellaAllenamenti* modello;
    DelegateEliminazione* delegato;

    QGroupBox* costruzioneFormPersona();
};

#endif // WIDGETRICERCA_H

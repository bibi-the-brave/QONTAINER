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
    QHBoxLayout *lNuoto, *lCiclismo, *lCorsa;
    QGroupBox *boxRicerca, *boxPersona, *boxNuoto, *boxCiclismo, *boxCorsa;
    QPushButton *btnRicerca;
    QRadioButton *rbNuoto, *rbCorsa, *rbCiclismo, *rbTriathlon, *rbAtleta;

    // ricerca atleta
    QComboBox* cmbAtleti;
    QHBoxLayout *lDate, *lMagnesio, *lDurata;
    QDateEdit *deDataInizio, *deDataFine;
    QSpinBox *spinMinMagnesio, *spinMaxMagnesio, *spinMinDurata, *spinMaxDurata;

    // ricerca nuoto
    QSpinBox *spinMinStile, *spinMaxStile, *spinMinRana, *spinMaxRana, *spinMinDorso, *spinMaxDorso;
    // ricerca ciclismo
    QSpinBox *spinMinSalita, *spinMaxSalita, *spinMinDiscesa, *spinMaxDiscesa, *spinMinPianura, *spinMaxPianura;
    // ricerca corsa
    QSpinBox *spinMinStrada, *spinMaxStrada, *spinMinSterrato, *spinMaxSterrato;

    QTableView* tabellaRicerca;
    ModelTabellaAllenamenti* modello;
    DelegateEliminazione* delegato;

    QGroupBox* costruzioneFormPersona();
    QGroupBox* costruzioneFormNuoto();
    QGroupBox* costruzioneFormCiclismo();
    QGroupBox* costruzioneFormCorsa();
public slots:
    void selezioneGroupBox();
    void gestioneSpinBoxOverflowMin(int);
    void gestioneSpinBoxUnderflowMax(int);
    void gestioneDate(const QDate &date);
    void aggiornamentoMinAllenamento(Allenamento*);
    void aggiornamentoMaxAllenamento(Allenamento*);
    void avvioRicerca();
signals:
    void allenamentoMin(Allenamento*);
    void allenamentoMAx(Allenamento*);
};

#endif // WIDGETRICERCA_H

#ifndef WIDGETRICERCA_H
#define WIDGETRICERCA_H

#include <QWidget>
#include "contenitore.h"
#include "allenamento.h"
#include "deepptr.h"
#include <memory>
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
#include <QString>
#include "widgetnuoto.h"
#include "widgetciclismo.h"
#include "widgetcorsa.h"
#include "modeltabellaallenamenti.h"
#include "sortfilterproxymodelallenamenti.h"
#include "delegateeliminazione.h"
#include "delegatemodifica.h"
#include "widgetallenamenti.h"

class WidgetRicerca : public QWidget {
    Q_OBJECT
public:
    WidgetRicerca(Contenitore<std::shared_ptr<Persona>>&,
                  Contenitore<DeepPtr<Allenamento>>&,
                  QWidget* = nullptr);
    ModelTabellaAllenamenti* getModello() const;
    SortFilterProxyModelAllenamenti* getProxy() const;
private:
    Contenitore<std::shared_ptr<Persona>>& cp;
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
    DelegateEliminazione* delegatoEl;
    DelegateModifica *delegatoMod;
    SortFilterProxyModelAllenamenti *proxy;

    QGroupBox* costruzioneFormPersona();
    QGroupBox* costruzioneFormNuoto();
    QGroupBox* costruzioneFormCiclismo();
    QGroupBox* costruzioneFormCorsa();

    void stampaMessaggioErrore(QString) const;
    bool verificaNuoto() const;
    bool verificaCiclismo() const;
    bool verificaCorsa() const;
    bool verificaTriathlon() const;
public slots:
    void selezioneGroupBox();
    void gestioneSpinBoxOverflowMin(int);
    void gestioneSpinBoxUnderflowMax(int);
    void gestioneDate(const QDate &date);
    void avvioRicerca();
    void ricevutaNotificaEliminazioneRiga(int);
    void avviaDialogModifica(int);
    // fa sparire una riga i cui elementi sono stati cancellati dal modello
    void rimozioneRigaEliminataModel(int);
signals:
    void allenamentoMin(Allenamento*);
    void allenamentoMax(Allenamento*);
    void selezioneTipo(int); // == 0 se selezionato rbAtleta, > 0 altrimenti
    int rimuovereRiga(int);
};

#endif // WIDGETRICERCA_H

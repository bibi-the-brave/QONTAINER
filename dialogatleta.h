/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#ifndef DIALOGINSERIMENTOATLETA_H
#define DIALOGINSERIMENTOATLETA_H

#include <QDialog>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "contenitore.h"
#include <memory>
#include <persona.h>
#include <QRadioButton>
#include <QGroupBox>

class DialogAtleta : public QDialog {
    Q_OBJECT
public:
    explicit DialogAtleta(Contenitore<std::shared_ptr<Persona>>&,
                          bool mod = false,
                          int rMod = 0, //se mod == 0 non uso rigaMod
                          QWidget* = nullptr);
private:
    QVBoxLayout *layoutPrincipale;
    QHBoxLayout *layoutBottoniConferma, *layoutRadioButton;
    QFormLayout *layoutForm;
    QLabel *lblTitolo, *lblNome, *lblCognome, *lblSesso;
    QLineEdit *leNome, *leCognome;
    QPushButton *bInserisci, *bAzzera;
    QRadioButton *rbUomo, *rbDonna;

    Contenitore<std::shared_ptr<Persona>>& atleti;
    bool modifica;
    int rigaMod;

    void compilazioneFormModifica();
    bool verificaCampiNomeCognome(QString, QString) const;
    bool verificaAtletaPresente(std::shared_ptr<Persona>& persona) const;
private slots:
    void inserimentoAtleta(bool);
    void modificaAtleta(bool);
    void azzeramentoForm(bool);
signals:
    void reset();
};

#endif // DIALOGINSERIMENTOATLETA_H

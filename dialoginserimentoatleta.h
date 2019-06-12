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

class DialogInserimentoAtleta : public QDialog {
    Q_OBJECT
public:
    explicit DialogInserimentoAtleta(Contenitore<std::shared_ptr<Persona>>&, QWidget* = nullptr);
private:
    QVBoxLayout layoutPrincipale;
    QHBoxLayout layoutBottoniConferma;
    QFormLayout layoutForm;
    QLabel lblTitolo, lblNome, lblCognome, lblSesso;
    QLineEdit leNome, leCognome;
    QPushButton bInserisci, bAzzera;
    QGroupBox gbSesso;
    QRadioButton rbUomo, rbDonna;

    Contenitore<std::shared_ptr<Persona>>& atleti;
private slots:
    void inserimentoAtleta(bool);
    void azzeramentoForm(bool);

signals:
    void reset();
};

#endif // DIALOGINSERIMENTOATLETA_H

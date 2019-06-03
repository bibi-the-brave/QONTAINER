#ifndef DIALOGINSERIMENTOATLETA_H
#define DIALOGINSERIMENTOATLETA_H

#include <QDialog>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class DialogInserimentoAtleta : public QDialog {
    Q_OBJECT
public:
    explicit DialogInserimentoAtleta(QWidget* = nullptr);
private:
    QVBoxLayout layoutPrincipale;
    QHBoxLayout layoutBottoniConferma;
    QFormLayout layoutForm;
    QLabel lblTitolo, lblNome, lblCognome;
    QLineEdit leNome, leCognome;
    QPushButton bInserisci, bAzzera;
private slots:
    void inserimentoAtleta(bool);
    void azzeramentoForm(bool);
};

#endif // DIALOGINSERIMENTOATLETA_H

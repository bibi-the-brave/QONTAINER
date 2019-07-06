#include "widgetintroduttivo.h"
#include <QVBoxLayout>

WidgetIntroduttivo::WidgetIntroduttivo(QWidget* parent) : QWidget (parent)
{
    layout = new QVBoxLayout;
    lBottoniDescrizione = new QFormLayout;
    lblTitolo = new QLabel;
    QPixmap banner(":/immagini/banner.svg");
    lblTitolo->setPixmap(banner);
    lblTitolo->setAlignment(Qt::AlignCenter);
    layout->addWidget(lblTitolo);

    lblDescrizione = new QLabel();
    lblDescrizione->setText("L'APPLICAZIONE PERMETTE DI:");
    lblDescrizione->setStyleSheet("font-weight: bold;");
    lblDescrizione->setAlignment(Qt::AlignCenter);
    layout->addWidget(lblDescrizione);

    btnAtleti = new QPushButton();
    btnAtleti->setIcon(QIcon(":/immagini/atleta.svg"));
    btnAtleti->setIconSize(QSize(75,75));
    btnAtleti->setToolTip("Premere per inserire, modificare ed eliminare atleti");
    lblAtleti = new QLabel;
    lblAtleti->setText("Gestire gli atleti.");
    lBottoniDescrizione->addRow(btnAtleti, lblAtleti);

    btnAllenamenti = new QPushButton();
    btnAllenamenti->setIcon(QIcon(":/immagini/allenamento.svg"));
    btnAllenamenti->setIconSize(QSize(75,75));
    btnAllenamenti->setToolTip("Premere per inserire, modificare ed eliminare allenamenti");
    lblAllenamenti = new QLabel;
    lblAllenamenti->setText("Gestire gli allenamenti.");
    lBottoniDescrizione->addRow(btnAllenamenti, lblAllenamenti);

    btnRicerca = new QPushButton();
    btnRicerca->setIcon(QIcon(":/immagini/ricerca.svg"));
    btnRicerca->setIconSize(QSize(75,75));
    btnRicerca->setToolTip("Premere per fare una ricerca sugli allenamenti");
    lblRicerca = new QLabel;
    lblRicerca->setText("Effettuare una ricerca sugli allenamenti.");
    lBottoniDescrizione->addRow(btnRicerca, lblRicerca);

    lBottoniDescrizione->setAlignment(Qt::AlignHCenter);
    QVBoxLayout *l = new QVBoxLayout;
    layout->addLayout(l);
    l->addLayout(lBottoniDescrizione);
    l->setAlignment((Qt::AlignHCenter));
    layout->setAlignment(Qt::AlignTop);
    setLayout(layout);
}

QPushButton* WidgetIntroduttivo::getBtnAtleti() const {
    return btnAtleti;
}

QPushButton* WidgetIntroduttivo::getBtnAllenamenti() const {
    return btnAllenamenti;
}

QPushButton* WidgetIntroduttivo::getBtnRicerca() const {
    return btnRicerca;
}

#ifndef WIDGETINTRODUTTIVO_H
#define WIDGETINTRODUTTIVO_H
#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QLabel>


class WidgetIntroduttivo : public QWidget {
    Q_OBJECT
public:
    explicit  WidgetIntroduttivo(QWidget* = nullptr);
    QPushButton* getBtnAtleti() const;
    QPushButton* getBtnAllenamenti() const;
    QPushButton* getBtnRicerca() const;
private:
    QVBoxLayout *layout;
    QFormLayout *lBottoniDescrizione;
    QPushButton *btnAtleti, *btnAllenamenti, *btnRicerca;
    QLabel *lblTitolo, *lblDescrizione, *lblAtleti, *lblAllenamenti, *lblRicerca;

};

#endif // WIDGETINTRODUTTIVO_H

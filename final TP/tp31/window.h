#ifndef WINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);


public slots:
    void echoChanged();
    void echoChanged2();
    void bouton();
    void aide();
    void ind();
    void ind2();

private:
    QPushButton *button1 = new QPushButton("Se connecter");
    QPushButton *button2 = new QPushButton("1");
    QPushButton *button3 = new QPushButton("2");
    QPushButton *button4 = new QPushButton("3");
    QPushButton *button5 = new QPushButton("4");
    QPushButton *button6 = new QPushButton("5");
    QPushButton *button7 = new QPushButton("6");
    QPushButton *button8 = new QPushButton("7");
    QPushButton *button9 = new QPushButton("8");
    QPushButton *button10 = new QPushButton("9");
    QPushButton *button11 = new QPushButton("0");

    QPushButton *boutonAide = new QPushButton("Aide");
    QPushButton *boutonQuitter = new QPushButton("Quitter");

    QString id = "11111111";
    QString mdp = "1234";
    QString id2 = "22222222";
    QString mdp2 = "4321";

    QLineEdit *echoLineEdit;
    QLineEdit *echoLineEdit2;
    QCheckBox *echoCheckBox;                // le pointeur sert à heriter des methodes de la clase qchekboxx sur les 2 instance
    QCheckBox *echoCheckBox2;
};

#endif // MAINWINDOW_H

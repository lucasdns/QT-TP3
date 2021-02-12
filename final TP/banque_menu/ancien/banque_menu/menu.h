#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QPushButton>

#include "client.h"
#include "compte.h"

class menu : public QWidget
{
    Q_OBJECT

public:
    menu(QWidget *parent = nullptr);
    ~menu();

    void crediter();
    void creditercompte();
    void debiter();
    void consulter();
    void virement();
    void commander();
    void afficher();

private:

    QPushButton *boutton1 = new QPushButton("Créditer un compte");
    QPushButton *boutton2 = new QPushButton("Créditer à partir d'un compte");
    QPushButton *boutton3 = new QPushButton("Débiter un compte");
    QPushButton *boutton4 = new QPushButton("Consulter RIB");
    QPushButton *boutton5 = new QPushButton("Virement à un compte");
    QPushButton *boutton6 = new QPushButton("Commander un Chéquier");
    QPushButton *boutton7 = new QPushButton("Afficher détail compte");

    int id_client = 1;
    int cin = 11111111;
    int tel = 0666666666;
    int mdp = 1234;
    QString nom = "denis";
    QString prenom = "lucas";
    int numero = 5555;
    float solde = 103;

    int id_client2 = 2;
    int cin2 = 22222222;
    int tel2 = 0777777777;
    int mdp2 = 4321;
    QString nom2 = "duval";
    QString prenom2 = "loic";
    int numero2 = 2;
    float solde2 = 50;
};
#endif // MENU_H

#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>


class menu : public QWidget
{
    Q_OBJECT

public:
    menu(QWidget *parent = nullptr);

public slots:
    void crediter();
    void creditercompte();//choix de la somme à virer à un compte
    void choixCompteCrediter();//choix du compte pour virement
    void debiter();
    //void virement();
    void commander();
    void aide();
    void contacte();
private:
    //boutons
    QPushButton *boutonAide = new QPushButton("Aide");//bouton aide du menu
    QPushButton *boutonContacter = new QPushButton("Nous contacter");//bouton nous contacter du menu
    QPushButton *boutonQuitter = new QPushButton("Quitter");//instanciation du bouton quittez

    //crediter
    QPushButton *boutonCrediter = new QPushButton("Crediter mon compte");//bouton crediter
    QLineEdit *editCrediter = new QLineEdit;//line edit de crediter
    QLabel *ajoutHisto = new QLabel;



    //crediter "virement" compte
    QLineEdit *editChoixCompte = new QLineEdit;//ecrire 1 ou 2 pour choisir le compte à virer.
    QPushButton *boutonCrediterCompte = new QPushButton("Suivant");//suivant et afficher le reste
    QLineEdit *editCrediterCompte = new QLineEdit;//entrez le nombre à crediter
    QLabel *choixCompte = new QLabel("Sur quel compte voulez vous faire le virement ?<br><br> 1) SI ALI <br> 2) Compte epargne <br><br> Pour rajouter des comptes contacter le service client. ");
    QPushButton *boutonChoix = new QPushButton("Virement à un compte");

    //debiter
    QPushButton *boutonDebiter = new QPushButton("Debiter mon compte");
    QLineEdit *editDebiter = new QLineEdit;

    //virement
    //QLineEdit *editChoixVirement = new QLineEdit;//ecrire 1 ou 2 pour choisir le compte à virer.
    //QPushButton *boutonVirement = new QPushButton("Suivant");//suivant et afficher le reste

    //chequier
    QPushButton *boutonChequier = new QPushButton("Commander un chequier");//bouton commande de commander chequier

    //solde
    QLabel *label_solde = new QLabel;
    QLabel *label_soldeEpargne = new QLabel;

    //historique
    QLabel *labelHistorique = new QLabel;
    QGridLayout *layoutHistorique = new QGridLayout;


    //client 1
    double cin = 11111111111;// 8 max
    double tel = 0652565254;//10 max
    double code = 1234;
    QString nom = "DENIS";
    QString prenom = "Lucas";//afficher info compte adresse mail, numero, adresse.
    double rib = 532514;
    int numero = 1;
    QString mail = "lucasdenis@banque.fr";
    QString adresse = "10 rue corbusier 75001, Paris";

    double solde = 5000;
    double soldeEpargne = 20;

    //client 2
    double cin2 = 22222222;//8 max
    double tel2 = 0774552652;//10 max
    double code2 = 4321;
    QString nom2 = "SI ALI";
    QString prenom2 = "Lyes";
    double rib2 = 332142;

    double solde2 = 2000;
    int numero2 = 2;

    double afficheSommeCrediter;
    double afficheSommeDebiter;
    double afficheSommeVirement;
};
#endif // MENU_H

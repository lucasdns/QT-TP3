#include "menu.h"
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QApplication>
#include <QMessageBox>
#include <QButtonGroup>
#include <QObject>
#include <QString>
#include <QRegExp>
#include <QRegExpValidator>


menu::menu(QWidget *parent): QWidget(parent)
{
    QGroupBox *GroupeInfo = new QGroupBox(tr(""));//instanciation du groupe box info
    QLabel *label_numerodecompte = new QLabel("Numéro de compte : " + QString::number(numero));//label qui affiche le numero de compte
    QLabel *label_nom = new QLabel("Nom : "+ nom);//label qui affiche le prenom
    QLabel *label_prenom = new QLabel("Prenom: "+ prenom);//label qui affiche le nom
    label_solde->setText("Solde : "+ QString::number(solde) + " €");//label qui affiche le solde
    label_soldeEpargne->setText("Solde compte épargne: "+ QString::number(soldeEpargne) + " €");//label qui affiche le solde epargne

    QGridLayout *layoutInfo = new QGridLayout;//instanciation du layout info.
    layoutInfo->addWidget(label_numerodecompte);//ajout du widget dans la layout info
    layoutInfo->addWidget(label_nom);//ajout du widget dans la layout info
    layoutInfo->addWidget(label_prenom);//ajout du widget dans la layout info
    layoutInfo->addWidget(label_solde);//ajout du widget dans la layout info
    layoutInfo->addWidget(label_soldeEpargne);//ajout du widget dans la layout info

    GroupeInfo->setLayout(layoutInfo);//ajout du groupe info sur le layout info

    // re interdit l'utilisation de "-"
    QRegExp re("[^-]+");//interdit l'utilisation du -
    QRegExpValidator *validator = new QRegExpValidator(re, this); //instantie un objet validator qui prend la fonction = interdire les -


    QGridLayout *layoutTotal = new QGridLayout;//instanciation du layout total de la fenetre

    layoutTotal->addWidget(GroupeInfo, 0, 0);//ajout du groupe box "groupe info" au layout total de la page
    setLayout(layoutTotal);//afficher le layout total


    //box bouton
    QGroupBox *boxBouton = new QGroupBox(tr(""));//instanciation du groupe box "bouton"
    QGridLayout *layoutBouton = new QGridLayout;//instanciation du layout bouton

    layoutBouton->addWidget(boutonAide,0, 1);//ajout du widget bouton aide dans le layout bouton
    layoutBouton->addWidget(boutonContacter, 0, 2);//ajout du widget bouton aide dans le layout bouton
    layoutBouton->addWidget(boutonQuitter,0, 3);//ajout du widget bouton aide dans le layout bouton

    boxBouton->setLayout(layoutBouton);//applique une mise en page au  widget.

    layoutTotal->addWidget(boxBouton, 2, 0);//ajout du groupe box bouton dans le layout total de la fenetre

    //box bouton
    QGroupBox *boxHistorique = new QGroupBox(tr(""));
    labelHistorique->setText("Historique : <br>");

    boxHistorique->setLayout(layoutHistorique); //applique une mise en page au  widget.
    layoutTotal->addWidget(boxHistorique, 3, 0);//ajout du box historique au layout total

    layoutHistorique->addWidget(labelHistorique); //ajout du label  historique au layout  historique

    //box selection
    QGroupBox *GroupeSelection = new QGroupBox(tr(""));
    QGridLayout *layoutSelection = new QGridLayout;

    GroupeSelection->setLayout(layoutSelection);
    layoutTotal->addWidget(GroupeSelection, 1, 0);//ajoute groupe selection au layout total

    //creation tab selection
    QTabWidget *selection = new QTabWidget;

    //crediter
    QWidget *page1 = new QWidget;
    QLabel *labelCrediter = new QLabel("Quelle somme voulez vous crediter ?");
    /* line edit dans le .h */
    QVBoxLayout *boxCrediter = new QVBoxLayout;

    editCrediter->setValidator(validator);

    /* bouton crediter dans le .h */
    boxCrediter->addWidget(labelCrediter);//que voulez vous faire
    boxCrediter->addWidget(editCrediter);//ecriture somme à crediter
    boxCrediter->addWidget(boutonCrediter);//bouton crediterajoutHisto


    //crediterCompte virement
    QWidget *page2 = new QWidget;
    /* bouton crediter compte dans le .h */
    QLabel *labelCrediterCompte = new QLabel("Quelle somme voulez vous virer ? ");
    /* line edit dans le .h*/
    QVBoxLayout *boxCrediterCompte = new QVBoxLayout;

    boxCrediterCompte->addWidget(labelCrediterCompte);// ecriture Combien voulez vous virer ?

    boxCrediterCompte->addWidget(editCrediterCompte);//entrez le nombre à virer
    boxCrediterCompte->addWidget(boutonCrediterCompte);//bouton suivant
    boxCrediterCompte->addWidget(choixCompte);//label choix compte
    boxCrediterCompte->addWidget(editChoixCompte);//ecrire 1 ou 2 pour choisir le compte à virer.
    boxCrediterCompte->addWidget(boutonChoix);//crediter le compte

    editCrediterCompte->setValidator(validator);
    editChoixCompte->setValidator(validator);

    choixCompte->hide();
    editChoixCompte->hide();
    boutonChoix->hide();

    //debiter compte
    QWidget *page3 = new QWidget;
    QLabel *labelDebiter = new QLabel("Quelle somme voulez vous debiter ?");

    editDebiter->setValidator(validator);
    /* bouton debiter dans .g */
    QVBoxLayout *boxDebiter = new QVBoxLayout;

    boxDebiter->addWidget(labelDebiter);
    boxDebiter->addWidget(editDebiter);
    boxDebiter->addWidget(boutonDebiter);

    //consulter rib d'un compte
    QWidget *page4 = new QWidget;
    QLabel *labelConsulter = new QLabel("Votre rib est : " + QString::number(rib));
    QLabel *labelConsulter2 = new QLabel("Pour plus d'information rendez vous dans aide, rubrique rib.");
    QVBoxLayout *boxConsulter = new QVBoxLayout;

    boxConsulter->addWidget(labelConsulter);
    boxConsulter->addWidget(labelConsulter2);

    //virement compte
    //QWidget *page5 = new QWidget;
    /* Bouton virement dans le .h */
   // QLabel *labelVirement = new QLabel("Quelle somme voulez vous virer ?");
    /* label virement dans le .h */
   // QVBoxLayout *boxVirement = new QVBoxLayout;

    //boxVirement->addWidget(labelVirement);// ecriture Combien voulez vous virer ?
    //boxVirement->addWidget(editChoixVirement);//entrez le nombre à crediter
    //boxVirement->addWidget(boutonVirement);//bouton suivant

    //commander chequier
    QWidget *page6 = new QWidget;
    QLabel *labelCheque = new QLabel("Cliquer pour commander un chequier");
    QLabel *labelCheque2 = new QLabel("Pour plus d'information rendez vous dans aide, rubrique chequier.");
    /* bouton chequier dans le .h */
    QVBoxLayout *boxCheque = new QVBoxLayout;

    boxCheque->addWidget(labelCheque);
    boxCheque->addWidget(labelCheque2);
    boxCheque->addWidget(boutonChequier);

    //afficher info compte adresse mail, numero, adresse.
    QWidget *page7 = new QWidget;
    QLabel *labelAfficher= new QLabel("Adresse mail du compte: " + mail);
    QLabel *labelAfficher2 = new QLabel("Adresse du compte: " + adresse);
    QLabel *labelAfficher3 = new QLabel("Numéro associé : ");
    QLabel *labelAfficher4 = new QLabel("Pour changer vos informations contacter le service client.");
    QVBoxLayout *boxAfficher = new QVBoxLayout;

    boxAfficher->addWidget(labelAfficher);
    boxAfficher->addWidget(labelAfficher2);
    boxAfficher->addWidget(labelAfficher3);
    boxAfficher->addWidget(labelAfficher4);

    //ajout des page au layout Qtab
    page1->setLayout(boxCrediter);
    page2->setLayout(boxCrediterCompte);
    page3->setLayout(boxDebiter);
    page4->setLayout(boxConsulter);
    //page5->setLayout(boxVirement);
    page6->setLayout(boxCheque);
    page7->setLayout(boxAfficher);

    //ajouter les onglets au qtabwidget en indiquant la page quils contiennt
    selection->addTab(page1, "Crediter");
    selection->addTab(page2, "Virement");
    selection->addTab(page3, "Debiter");
    selection->addTab(page4, "RIB");
    //selection->addTab(page5, "Virement");
    selection->addTab(page6, "Chequier");
    selection->addTab(page7, "Afficher");
    layoutSelection->addWidget(selection);//ajout à la table


    setWindowTitle(tr("Banque"));//choix nom de l'app
    this->setStyleSheet("background-color: rgb(169,234,254);");//choix couleur fond d'écran

    connect(boutonAide , SIGNAL(clicked()),this, SLOT(aide()));
    connect(boutonContacter , SIGNAL(clicked()),this, SLOT(contacte()));
    connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(boutonChequier , SIGNAL(clicked()),this, SLOT(commander()));
     connect(boutonCrediter , SIGNAL(clicked()),this, SLOT(crediter()));
     connect(boutonCrediterCompte , SIGNAL(clicked()),this, SLOT(creditercompte()));
     connect(boutonDebiter , SIGNAL(clicked()),this, SLOT(debiter()));
     //connect(boutonVirement , SIGNAL(clicked()),this, SLOT(virement()));
     connect(boutonChoix , SIGNAL(clicked()),this, SLOT(choixCompteCrediter()));
}


void menu::crediter()
{ 
    solde = solde + editCrediter->text().toDouble();//operation

    afficheSommeCrediter = editCrediter->text().toDouble(); //prend la valeur que l'on vient d'écrire et la mets dans afficheSommeCrediter

    label_solde->setText("Solde : "+ QString::number(solde) + " €");//mise à jour de la valeur de solde
    editCrediter->clear();//enleve la somme que l'on vient de rentrer du lineedit

    QLabel *ajoutSommeHistorique = new QLabel;//label ajout dans historique

    ajoutSommeHistorique->setText("Crédit + " + QString::number(afficheSommeCrediter) + " €");
    layoutHistorique->addWidget(ajoutSommeHistorique);
}

void menu::creditercompte()
{
   boutonCrediterCompte->setDisabled(1);
   choixCompte->show();//montre choixCompte
   editChoixCompte->show();//montre editChoixCompte
   boutonChoix->show();//montre boutonChoix
}

void menu::choixCompteCrediter()
{
    if (editChoixCompte->text().toDouble() == 1)
    {
        solde = solde - editCrediterCompte->text().toDouble();//prelevement dans mon compte

        afficheSommeVirement = editCrediterCompte->text().toDouble(); //prend la valeur que l'on vient d'écrire et la mets dans afficheSommeCrediter

        label_solde->setText("Solde : "+ QString::number(solde) + " €");//mise à jour de la valeur de solde

        solde2 = solde2 + editCrediterCompte->text().toDouble();//operation

        editCrediterCompte->clear();//enleve la somme que l'on vient de rentrer du lineedit
        editChoixCompte->clear();//enleve la somme que l'on vient de rentrer du lineedit


        QLabel *ajoutSommeHistorique = new QLabel;//label ajout dans historique

        ajoutSommeHistorique->setText("Le compte de " + nom2 + " " + prenom2 + " à été credité de + " + QString::number(afficheSommeCrediter) + " €");
        layoutHistorique->addWidget(ajoutSommeHistorique);

        choixCompte->hide();//cache choixCompte
        editChoixCompte->hide();//cache editChoixCompte
        boutonChoix->hide();//cache boutonChoix
        boutonCrediterCompte->setDisabled(0);//desactive

    }
    else if (editChoixCompte->text().toDouble() == 2)
    {
        soldeEpargne = soldeEpargne + editCrediterCompte->text().toDouble();//rajout dans mon compte epargne

        afficheSommeVirement = editCrediterCompte->text().toDouble(); //prend la valeur que l'on vient d'écrire et la mets dans afficheSommeCrediter

        label_soldeEpargne->setText("Solde compte épargne: "+ QString::number(soldeEpargne) + " €");//mise à jour de la valeur de solde epargne

        solde = solde - editCrediterCompte->text().toDouble();//prelevement dans mon compte
        label_solde->setText("Solde : "+ QString::number(solde) + " €");
        editCrediterCompte->clear();//enleve la somme que l'on vient de rentrer du lineedit
        editChoixCompte->clear();//enleve la somme que l'on vient de rentrer du lineedit

        QLabel *ajoutSommeHistorique = new QLabel;//label ajout dans historique

        ajoutSommeHistorique->setText("Le compte épargne à été credité de + " + QString::number(afficheSommeCrediter) + " €");
        layoutHistorique->addWidget(ajoutSommeHistorique);// ajout d'un layout


        choixCompte->hide();//cache choixCompte
        editChoixCompte->hide();//cache editChoixCompte
        boutonChoix->hide();//cache boutonChoix
        boutonCrediterCompte->setDisabled(0);//desactive bouton suivant
    }
}

void menu::debiter()
{
    solde = solde - editDebiter->text().toDouble();//operation

    afficheSommeDebiter = editDebiter->text().toDouble(); //prend la valeur que l'on vient d'écrire et la mets dans afficheSommeDebiter

    label_solde->setText("Solde : "+ QString::number(solde) + " €");//mise à jour de la valeur de solde
    editDebiter->clear();//enleve la somme que l'on vient de rentrer du lineedit

    QLabel *ajoutSommeHistorique = new QLabel;//label ajout dans historique

    ajoutSommeHistorique->setText("Débit - " + QString::number(afficheSommeDebiter) + " €");
    layoutHistorique->addWidget(ajoutSommeHistorique);// ajout d'un layout
}

/*
void menu::virement()
{
    solde = solde - editChoixVirement->text().toDouble();//operation
    label_solde->setText("Solde : "+ QString::number(solde) + " €");//mise à jour de la valeur de solde

    soldeEpargne = soldeEpargne + editChoixVirement->text().toDouble();//Operation
    label_soldeEpargne->setText("Solde compte épargne: "+ QString::number(soldeEpargne) + " €");//mise à jour de la valeur de solde epargne

    labelHistorique->setText("Votre nouveau solde eparge est: " + QString::number(soldeEpargne));//mise a jour historique
    editChoixVirement->clear();//enleve la somme que l'on vient de rentrer du lineedit
}*/


void menu::commander()
{
    QMessageBox::information(this, "Commande effectué", "Chequier envoyé à l'adresse suivant : " + adresse + "<br><br>Livraison dans les 5 prochains jours ouvrés.");
    boutonChequier->setDisabled(1);
}

void menu::aide()
{
    QMessageBox::information(this, "Aide", "RIB :<br> 1) Si vôtre rib ne s'affiche pas, declaré le au service client par téléphone.<br> 2) Pour éditer vôtre rib, contacter le service client par mail. <br><br> Chéquier:<br>1) Vous ne pouvez pas commander 2 chéquiers d'affilés.<br>2) Après la commande le chéquier arrivera sous 10 jours maximum, passé ce delai contacter vôtre conseiller client.<br>3) Si le bouton <Commander un chequier> est grisé, c'est que un chéquier est deja en cours de livraison.<br> 4)Vous pouvez suivre vôtre commande de chéquier en envoyant -chequier- au 5504. <br><br><br> Pour tout autre information contacter le service client, coordonnées dans -Nous contacter- merci de vôtre fidélité.  ");
}

void menu::contacte()
{
    QMessageBox::information(this, "Aide", "Notre numero : 0125652362 <br> Notre mail: abcf@abcd.fr<br>Notre adresse :");
}


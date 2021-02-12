#include "window.h"
#include "menu.h"
#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QInputDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QString>
#include <QApplication>
#include <QButtonGroup>
#include <QColorDialog>

Window::Window(QWidget *parent): QWidget(parent)
 {
    QGroupBox *echoGroup = new QGroupBox(tr(""));                           // instancie lobjet echogroup de type pointeur de la classe qgroup box

    QLabel *echoLabel = new QLabel(tr("Identifiant (8 chiffres) :"));       // instancie lobjet echolabel de type pointeur de la classe QLabel

    echoCheckBox = new QCheckBox("Masquer");                                // definition du pointeur echocheckbox de la classe qgroupbox
    echoCheckBox2 = new QCheckBox("Masquer");                               // definition du pointeur echocheckbox2 de la classe qgroupbox

    QLabel *echoLabel2 = new QLabel(tr("Mot de passe (4 chiffres) :"));     // afficher un texte pour pour mot de passe

    echoLineEdit = new QLineEdit;                                           // definition du pointeur echolineedit pour l'identifiant de la classe QLineEdit
    echoLineEdit->setPlaceholderText("Entrer votre identifiant.");          // Mise en place d'un texte en fond de zone d'écriture de l'identifiant

    echoLineEdit2 = new QLineEdit;                                          // definition du pointeur echolineedit2 du mdp de la classe QLineEdit
    echoLineEdit2->setPlaceholderText("Entrer votre mot de passe.");        // Mise en place d'un texte en fond de zone d'écriture du mdp

    echoLineEdit2->setMaxLength(4);                                         // longueur max du mot de passe
    echoLineEdit->setMaxLength(8);                                          // longueur max de l'identifiant

    echoLineEdit2->setDisabled(1);                                          // desactivation de la case mot de passe
    button1->setDisabled(1);                                                // desactivation du bouton connection

    QGridLayout *echoLayout = new QGridLayout;                              // ajout du layout, instancie lobjet ecolayout de type pointeur de la classe QGridLayout
    echoLayout->addWidget(echoLabel, 0, 0);                                 // ajout du widget d'affichage de texte identifiant
    echoLayout->addWidget(echoLabel2, 3, 0);                                // ajout du widget d'affichage de texte mdp

    echoLayout->addWidget(echoLineEdit, 2, 0, 1, 1);                        // ajout du widget zone décriture pour l'identifiant
    echoLayout->addWidget(echoLineEdit2, 5, 0, 1, 1);                       // ajout du widget zone décriture pour le mdp

    echoLayout->addWidget(echoCheckBox, 1, 0);                              // ajout du widget bouton masque ou non pour identifiant
    echoLayout->addWidget(echoCheckBox2, 4, 0);                             // ajout du widget bouton masque ou non pour le mdp

    echoLayout->addWidget(button1, 7, 0, 1, 1);                             // ajout du widget bouton Se connecter à un certain emplacement
    echoLayout->addWidget(button2, 1, 5);                                   // ajout du widget bouton 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
    echoLayout->addWidget(button3, 1, 6);
    echoLayout->addWidget(button4, 1, 7);
    echoLayout->addWidget(button5, 2, 5);
    echoLayout->addWidget(button6, 2, 6);
    echoLayout->addWidget(button7, 2, 7);
    echoLayout->addWidget(button8, 3, 5);
    echoLayout->addWidget(button9, 3, 6);
    echoLayout->addWidget(button10,3, 7);
    echoLayout->addWidget(button11,4, 6);
    echoLayout->addWidget(boutonQuitter, 7, 7);                                // ajout du widget bouton quitter à un certain emplacement
    echoLayout->addWidget(boutonAide, 7, 6);
    //->setext();
    echoGroup->setLayout(echoLayout);                                          // ajout des widgets du groupe a la fenetre !!indispensable!!

    QGridLayout *layout = new QGridLayout;                                     // création du layout, pointeur pour heriter de la classe qgridlayout

    layout->addWidget(echoGroup, 0, 0);                                        // 0,0 définit la position de notre layout
    setLayout(layout);

     setWindowTitle(tr("Authentification"));                                    // définit le titre de l'application
     this->setStyleSheet("background-color: rgb(169,234,254);");
     connect(button2 , SIGNAL(clicked()),this, SLOT(bouton()));                // lorsqu'on appui sur le bouton 2, excecute la fonction bouton()
     connect(button3 , SIGNAL(clicked()),this, SLOT(bouton()));
     connect(button4 , SIGNAL(clicked()),this, SLOT(bouton()));
     connect(button5 , SIGNAL(clicked()),this, SLOT(bouton()));
     connect(button6 , SIGNAL(clicked()),this, SLOT(bouton()));
     connect(button7 , SIGNAL(clicked()),this, SLOT(bouton()));
     connect(button8 , SIGNAL(clicked()),this, SLOT(bouton()));
     connect(button9 , SIGNAL(clicked()),this, SLOT(bouton()));
     connect(button10 ,SIGNAL(clicked()),this, SLOT(bouton()));
     connect(button11 ,SIGNAL(clicked()),this, SLOT(bouton()));

     connect(echoCheckBox, SIGNAL(clicked()), this, SLOT(echoChanged()));                    // lorsque l'on clique sur masquer ou non, cela excecute la fonction echoChanged()
     connect(echoCheckBox2, SIGNAL(clicked()), this, SLOT(echoChanged2()));                  // lorsque l'on clique sur masquer ou non, cela excecute la fonction echoChanged()

     connect(button1, SIGNAL(clicked()), this, SLOT(ind2()));                                 // lorsque l'on clique sur le bouton 1 "connecter" cela excecute la fonction ind()


     connect(echoLineEdit,SIGNAL(textChanged(QString)),this,SLOT(ind()));    // lorsque l'on clique sur masque ou non, cela excecute la fonction echoChanged()

     connect(boutonAide, SIGNAL(clicked()), this, SLOT(aide()));                          //lorsque l'on clique sur le bouton quitter, l'appli se ferme
     connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));                          //lorsque l'on clique sur le bouton quitter, l'appli se ferme
}



void Window::bouton()
{
    QPushButton *button = (QPushButton *)sender();
    int num_button = (button->text()[0].digitValue());
    echoLineEdit->setText(echoLineEdit->text()+QString::number(num_button));


    if(echoLineEdit2->isEnabled())
       {
           echoLineEdit2->setText(echoLineEdit2->text()+QString::number(num_button));
           button1->setDisabled(0);
           button1->setStyleSheet("QPushButton {background-color: rgb(255,0,0)}");
       }

    if(echoLineEdit2->text() == mdp){

           button1->setEnabled(true);
           button1->setStyleSheet("QPushButton {background-color: rgb(0,255,0)}");

   }

    if ( echoLineEdit->text() == id)
    {
        //button1->setDisabled(0);
    }
}



void Window::ind2()
{

    if ( echoLineEdit2->text() == mdp)
    {
        QMessageBox::information(this, "Bienvenue", "Authentification réussi");

        menu *lk = new menu;

        lk->show();
    }
    else if ( echoLineEdit2->text() != mdp)
    {
        QMessageBox::warning(this, "Erreur", "Veuillez réessayer il vous reste 3 chances");
    }

    /*if ( echoLineEdit2->text() == mdp)
        {
            QMessageBox::information(this, "Bienvenue", "Authentification réussi");
        }
    else if (echoLineEdit2->text() != mdp)
    {
        int i;

        for(i=0;i<3;i=i+1)
        {
             if ( echoLineEdit2->text() == mdp)
                 {
                     QMessageBox::information(this, "Bienvenu", "Authentification réussi");
                 }
                 else if ( echoLineEdit2->text() != mdp)
                 {
                     QMessageBox::information(this, "Bienvenu", "ffff réussi");
                 }
        }
    }*/
}



void Window::ind()
{
    if(echoLineEdit->text()== id)
    {
        echoLineEdit->setDisabled(1);
        echoLineEdit2->setDisabled(0);
    }
}

void Window::echoChanged()
{
    if(echoCheckBox->isChecked()){
     echoLineEdit->setEchoMode(QLineEdit::Password);
}
    else if (!echoCheckBox->isChecked()) {
     echoLineEdit->setEchoMode(QLineEdit::Normal);
    }
}

void Window::echoChanged2()
{
    if(echoCheckBox2->isChecked()){
     echoLineEdit2->setEchoMode(QLineEdit::Password);
}
    else if (!echoCheckBox2->isChecked()) {
     echoLineEdit2->setEchoMode(QLineEdit::Normal);
    }
}

void Window::aide()
{
   QMessageBox::information(this, "Aide", "Pour vous authentifier :<br><br>1) Entrer vôtre identifiant avec le clavier<br><br>2) Entrez vôtre mot de passe avec le pavé numérique<br><br>3) Connecter vous<br><br><br>Pour plus d'information, contacter le service client au 0152222222. ");
}


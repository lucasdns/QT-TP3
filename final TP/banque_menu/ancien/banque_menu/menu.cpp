#include "menu.h"
#include "QLabel"
#include "QGridLayout"
#include "QGroupBox"

menu::menu(QWidget *parent): QWidget(parent)
{
    QGroupBox *groupeBouton = new QGroupBox(tr(""));
    QGridLayout *layoutBouton = new QGridLayout;

    layoutBouton->addWidget(boutton1, 1, 1);
    layoutBouton->addWidget(boutton2, 2, 1);
    layoutBouton->addWidget(boutton3, 3, 1);
    layoutBouton->addWidget(boutton4, 1, 2);
    layoutBouton->addWidget(boutton5, 2, 2);
    layoutBouton->addWidget(boutton6, 3, 2);
    layoutBouton->addWidget(boutton7, 4, 1);

    groupeBouton->setLayout(layoutBouton);

    QGridLayout *layoutTotal = new QGridLayout;

    setLayout(layoutTotal);
    layoutTotal->addWidget(groupeBouton, 2, 0);


    QGroupBox *GroupInfo = new QGroupBox(tr(""));
    QGridLayout *LayoutInfo = new QGridLayout;
    QLabel *label_numerodecompte = new QLabel;
    QLabel *label_nom = new QLabel;
    QLabel *label_prenom = new QLabel;
    QLabel *label_solde = new QLabel;

    label_numerodecompte->setText("N° de compte: ");
    label_nom->setText("Nom: ");
    label_prenom->setText("Prénom: ");
    label_solde->setText("Solde: ");

    LayoutInfo->addWidget(label_numerodecompte, 0, 0);
    LayoutInfo->addWidget(label_nom, 1, 0);
    LayoutInfo->addWidget(label_prenom, 2, 0);
    LayoutInfo->addWidget(label_solde, 3, 0);

    GroupInfo->setLayout(LayoutInfo);

    layoutTotal->addWidget(GroupInfo, 1, 0);

    QGroupBox *GroupOperation = new QGroupBox(tr(""));
    QGridLayout *LayoutOperation = new QGridLayout;
    QLabel *label_operation = new QLabel;

    label_operation->setText("Operation: ");
    LayoutOperation->addWidget(label_operation, 2, 0);
    GroupOperation->setLayout(LayoutOperation);
    layoutTotal->addWidget(GroupOperation, 3, 0);


     setWindowTitle(tr("Banque"));
     this->setStyleSheet("background-color: rgb(169,234,254);");

     connect(boutton1 , SIGNAL(clicked()),this, SLOT(crediter()));
     connect(boutton2 , SIGNAL(clicked()),this, SLOT(creditercompte()));
     connect(boutton3 , SIGNAL(clicked()),this, SLOT(debiter()));
     connect(boutton4 , SIGNAL(clicked()),this, SLOT(consulter()));
     connect(boutton5 , SIGNAL(clicked()),this, SLOT(virement()));
     connect(boutton6 , SIGNAL(clicked()),this, SLOT(commander()));
     connect(boutton7 , SIGNAL(clicked()),this, SLOT(afficher()));
}

menu::~menu()
{

}

void menu::crediter()
{

}

void menu::creditercompte()
{

}

void menu::debiter()
{

}

void menu::consulter()
{

}

void menu::virement()
{

}

void menu::commander()
{

}


void menu::afficher()
{

}

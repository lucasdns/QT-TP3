#include "window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.show();                   // pour affiche l'opération
    return a.exec();            // boucle d'évènement, démarre l'application

}

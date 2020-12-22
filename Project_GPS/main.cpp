#include "mainwindow.h"
#include "dialog.h"
#include "../GestionFichier/fichier.h"
#include <QApplication>
#include <windows.h>
#include <QStyleFactory>
#include <iostream>
#include "ruegene.h"
#include "../GestionFichier/fichier.h"
#include "rueindividu.h"
#include "parametres.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("QtProject");
    QCoreApplication::setApplicationName("Project GPS");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    SetConsoleOutputCP(CP_UTF8);

    Rue r;
    r.init();

    MainWindow w;
    w.show();

    return a.exec();
}

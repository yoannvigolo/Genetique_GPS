#include "rue.h"

using namespace std;

void Rue::init()
{
    QString fileName = "C:/Users/yoann/OneDrive/Documents/qt_projects/Project_GPS/Rues/rueName.txt";
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);

    QStringList listeInfoRue;
    QString ligne;

    while(!flux.atEnd())
    {
        listeInfoRue << flux.readLine();
    }

    foreach (QString item, listeInfoRue) {
        QRegExp exp1(";");
        QRegExp exp2(",");
        QStringList e1 = item.split(exp1);

        QString nomRue = e1[0];
        RueGene *r = new RueGene(nomRue);

        for(int i=1;i<e1.size();i++){
            QStringList e2 = e1.at(i).split(exp2);
            r->ajouteBout(new BoutdeRue(e2[0].toInt(), e2[1].toInt()));
        }

        rues.append(r);
    }
}

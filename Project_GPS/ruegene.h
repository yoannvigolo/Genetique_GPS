#ifndef RUEGENE_H
#define RUEGENE_H

#include <QLineF>
#include <QList>
#include <QString>
#include "boutderue.h"
#include <iostream>

using namespace std;

class RueGene
{

public:
    RueGene(QString name);
    RueGene(RueGene &rg);

    void ajouteBout(BoutdeRue *boutDeRue);
    void toString();

    QList<QPoint> getBoutList() const;
    QString getNomRue() const;

private:
    QString m_nomRue;
    QList<QPoint> boutList;

};

#endif // RUEGENE_H

#ifndef RUEINDIVIDU_H
#define RUEINDIVIDU_H

#include <QList>
#include "ruegene.h"
#include "rue.h"
#include "parametres.h"
#include "QTextStream"
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QPainterPath>
#include <iostream>
#include "rueevolutionary.h"

class RueIndividu
{

public:
    RueIndividu(QPoint start, QPoint stop);

    void init();
    void mutate();
    void perimetre(QPoint a, QPoint b);
    QPoint nbrRandom(QList<QPoint> list);
    int indexRandom(QList<QPoint> list);
    int longueurRue();

    inline static QList<QPoint> m_Pointpath;
    inline static QPainterPath m_perimetre;

    void setStart(const QPoint &value);
    void setStop(const QPoint &value);

    rueEvolutionary getEvolution() const;

private:
    int m_fitnessLongueur = -1;
    QPoint Start;
    QPoint Stop;
    QList<QPoint > m_listPointAutour;
    QList<QPoint > m_listNextStreet;
    int streetLenght = 0;
    rueEvolutionary evolution;

};

#endif // RUEINDIVIDU_H

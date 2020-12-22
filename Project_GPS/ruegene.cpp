#include "ruegene.h"

RueGene::RueGene(QString name)
    :   m_nomRue(name)
{
}

RueGene::RueGene(RueGene &rg)
{
    m_nomRue = rg.m_nomRue;
}

void RueGene::ajouteBout(BoutdeRue *boutDeRue)
{
    QPoint p;
    p.setX(boutDeRue->getX());
    p.setY(boutDeRue->getY());

    boutList.append(p);
}

void RueGene::toString()
{
    QString rueName = QString("Le nom de la rue est : %1 \n").arg(m_nomRue);
    QString coorPoint = rueName;
    foreach (QPointF point, boutList) {
        coorPoint +="["+QString::number(point.x())+","+QString::number(point.y())+"]";
    }
    cout << coorPoint.toStdString() << endl;
}

QString RueGene::getNomRue() const
{
    return m_nomRue;
}

QList<QPoint> RueGene::getBoutList() const
{
    return boutList;
}

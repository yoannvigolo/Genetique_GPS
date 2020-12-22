#ifndef RUEEVOLUTIONARY_H
#define RUEEVOLUTIONARY_H

#include <QList>

class rueEvolutionary
{
public:
    rueEvolutionary();

    void setPopulation(int valeur);
    void sortPopulation();
    void run();

    QList<int> getPopulation() const;

    void setBestPoint(const QList<QPoint> &bestPoint);

    inline static QList<QPoint>m_bestPoint;

private:
    QList<int>population;

};

#endif // RUEEVOLUTIONARY_H

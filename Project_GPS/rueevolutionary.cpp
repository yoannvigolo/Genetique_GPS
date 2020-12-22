#include "rueevolutionary.h"
#include "rueindividu.h"

rueEvolutionary::rueEvolutionary()
{

}

void rueEvolutionary::setPopulation(int valeur)
{
    population.append(valeur);
}

void rueEvolutionary::sortPopulation()
{
    std::sort(population.begin(), population.end());
}

void rueEvolutionary::run()
{
    sortPopulation();
    int bestInd = population[0];
    qDebug() << "Le meilleur fitness trouvé est :" << bestInd;
}

QList<int> rueEvolutionary::getPopulation() const
{
    return population;
}

void rueEvolutionary::setBestPoint(const QList<QPoint> &bestPoint)
{
    m_bestPoint = bestPoint;
}

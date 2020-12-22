#include "rueindividu.h"

using namespace std;

RueIndividu::RueIndividu(QPoint start, QPoint stop)
    :   Start(start), Stop(stop)
{
    m_Pointpath.append(Start);
    perimetre(Start, Stop);

}

void RueIndividu::init()
{
relance:
    int compteur = 0;
    m_listNextStreet.clear();
    m_listPointAutour.clear();

    while(Start != Stop){

        foreach (RueGene* r, rues) { // remplie list des prochains bouts de rue
            for(int i=0; i<r->getBoutList().size(); i++){
                if(r->getBoutList()[i].x() == Start.x() && r->getBoutList()[i].y() == Start.y()){
                    if(i == 0){
                        m_listPointAutour.append(QPoint(r->getBoutList()[i+1].x(), r->getBoutList()[i+1].y()));
                    }

                    else if(i == (r->getBoutList().size())-1){
                        m_listPointAutour.append(QPoint(r->getBoutList()[i-1].x(), r->getBoutList()[i-1].y()));
                    }

                    else{
                        m_listPointAutour.append(QPoint(r->getBoutList()[i-1].x(), r->getBoutList()[i-1].y()));
                        m_listPointAutour.append(QPoint(r->getBoutList()[i+1].x(), r->getBoutList()[i+1].y()));
                    }
                }
            }
        }

        foreach (QPoint b, m_listPointAutour) {
            if(m_perimetre.contains(b) == true){
                m_listNextStreet.append(b);
            }
            else{
                m_listPointAutour.removeOne(b);
            }
        }

        QPoint nombre = nbrRandom(m_listNextStreet);

        while (m_Pointpath.contains(nombre) == true) {
            nombre = nbrRandom(m_listNextStreet);
            compteur += 1;
            if(compteur == 100){
                Start = m_Pointpath[0];
                m_Pointpath.clear();
                m_Pointpath.append(Start);
                goto relance;
            }
        }
        compteur = 0;
        m_listPointAutour.clear();

        Start = nombre;
        m_Pointpath.append(Start);

        m_listNextStreet.clear();
    }

    qDebug() <<"Longueur du trajet :" <<longueurRue()<<"m";

    if(evolution.getPopulation().isEmpty()){
        evolution.setPopulation(longueurRue());
        evolution.setBestPoint(m_Pointpath);
    }

    else{
        evolution.setPopulation(longueurRue());
        evolution.sortPopulation();
        if(longueurRue() <= evolution.getPopulation().first()){
            evolution.setBestPoint(m_Pointpath);
        }
    }

}

void RueIndividu::mutate()
{
    if(Parametres::randomGenerator->getFloat() < Parametres::mutationRate){
        m_Pointpath.removeAt(m_Pointpath.size()-1);
        int Index_random = indexRandom(m_Pointpath);
        while (Index_random+1 != m_Pointpath.size()) {
            m_Pointpath.removeLast();
        }
        Start = m_Pointpath[Index_random];
        init();
    }
}

void RueIndividu::perimetre(QPoint a, QPoint b)
{
    QPoint milieu((a.x()+b.x())/2, (a.y()+b.y())/2);
    m_perimetre.addEllipse(milieu, int(QLineF(a,b).length()/1.5), int(QLineF(a,b).length()/1.5));
}

QPoint RueIndividu::nbrRandom(QList<QPoint> list)
{
    int index = Parametres::randomGenerator->get(list.size());
    return QPoint(list[index]);
}

int RueIndividu::indexRandom(QList<QPoint> list)
{
    int index = Parametres::randomGenerator->get(list.size());
    return index;
}

int RueIndividu::longueurRue()
{
    streetLenght = 0;
    double valeur = 0;
    for(int i=0; i<m_Pointpath.size()-1; i++){
        QLineF longueur(m_Pointpath[i], m_Pointpath[i+1]);
        valeur += longueur.length();
    }

    streetLenght = (int(valeur)*57)/50;

    return streetLenght;
}

void RueIndividu::setStart(const QPoint &value)
{
    Start = value;
}

void RueIndividu::setStop(const QPoint &value)
{
    Stop = value;
}

rueEvolutionary RueIndividu::getEvolution() const
{
    return evolution;
}

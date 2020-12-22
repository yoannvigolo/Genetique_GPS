#ifndef PARAMETRES_H
#define PARAMETRES_H

#include <QString>
#include <iostream>
#include <myrandom.h>


class Parametres
{
public:
    Parametres();

    static int individualsNb;
    static int generationsMaxNb;
    static int initialGenesNb;
    static int minFitness;

    static double mutationRate;
    static double mutationAddRate;
    static double mutationDeleteRate;
    static double crossoverRate;

    static MyRandom *randomGenerator;

    static int debug;
    static void print(QString txt, int d);
};

#endif // PARAMETRES_H

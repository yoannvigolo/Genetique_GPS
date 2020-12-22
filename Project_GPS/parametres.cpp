#include "parametres.h"

using namespace std;

Parametres::Parametres()
{
}
int Parametres::individualsNb = 200;
int Parametres::generationsMaxNb = 3;
int Parametres::initialGenesNb = 5;
int Parametres::minFitness = 15;

double Parametres::mutationRate = 1;
double Parametres::mutationAddRate = 0.2;
double Parametres::mutationDeleteRate = 0.1;
double Parametres::crossoverRate = 0.6;
// TODO : modifier la graine
MyRandom *Parametres::randomGenerator=new MyRandom();

int Parametres::debug = 1;

void Parametres::print(QString txt, int d)
{
    if(d<debug)
        cout<<txt.toStdString()<<endl;
}

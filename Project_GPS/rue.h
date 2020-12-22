#ifndef RUE_H
#define RUE_H

#include <QString>
#include <QList>
#include "ruegene.h"
#include <iostream>
#include <QTextStream>
#include <QDebug>

inline QList<RueGene *> rues;

class Rue
{
public:
    static void init();
};

#endif // RUE_H

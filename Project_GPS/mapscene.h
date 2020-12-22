#ifndef MAPSCENE_H
#define MAPSCENE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "dialog.h"
#include "rueindividu.h"
#include "rueevolutionary.h"
#include "mainwindow.h"
#include "qprogressbar.h"


class mapScene : public QGraphicsScene
{
public:
    mapScene(QObject *parent = nullptr);

    void addPoint(QPointF p);
    void createLine();

    bool isEmptyList();

    QList<QPoint> getStart_Stop_pointList() const;

private:
    QList<QPoint> Start_Stop_pointList;
    QProgressBar* bar;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // MAPSCENE_H

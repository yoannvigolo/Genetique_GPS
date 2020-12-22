#include "mapscene.h"

mapScene::mapScene(QObject *parent)
    :   QGraphicsScene(parent)
{
    QString filename = "C:/Users/yoann/OneDrive/Documents/qt_projects/Project_GPS/map.png";
    QImage image(filename);

    addPixmap(QPixmap::fromImage(image));

    addWidget(bar = new QProgressBar());
    bar->setGeometry(QRect(0, 805, 1240, 31));
    bar->setValue(0);
}

void mapScene::addPoint(QPointF p)
{
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(Qt::red));

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);

    addEllipse(p.x() - 5, p.y() - 5, 10, 10, pen, brush);
}

void mapScene::createLine()
{
    if(Start_Stop_pointList.size() == 2){
        QPen pen;
        pen.setWidth(5);
        pen.setColor(QColor(Qt::black));

        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::red);

        QLineF ligne;

        for(int i = 0; i < rueEvolutionary::m_bestPoint.size() - 1; i++){
            QPointF a(rueEvolutionary::m_bestPoint[i]);
            QPointF b(rueEvolutionary::m_bestPoint[i+1]);
            ligne.setPoints(a,b);
            addLine(ligne, pen);
            addPoint(rueEvolutionary::m_bestPoint.at(i));
            addPoint(rueEvolutionary::m_bestPoint.at(i+1));
        }

        bar->setValue(100);
    }
    else{
        return;
    }
}

bool mapScene::isEmptyList()
{
    return(RueIndividu::m_Pointpath.size() == 0 || RueIndividu::m_Pointpath.size() == 1);
}

QList<QPoint> mapScene::getStart_Stop_pointList() const
{
    return Start_Stop_pointList;
}

void mapScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    int x = int (event->scenePos().rx());
    int y = int (event->scenePos().ry());

    QPoint p(x,y);

    foreach (RueGene* r, rues) {
        foreach (QPoint point, r->getBoutList()) {
            if((point.x()-5 < p.x() && p.x() < point.x()+5) && (point.y()-5 < p.y() && p.y() < point.y()+5)){
                Start_Stop_pointList.append(point);
                addPoint(point);
                goto end;
            }
        }
    }
end:
    if(getStart_Stop_pointList().size() == 2){
        RueIndividu p(getStart_Stop_pointList()[0], getStart_Stop_pointList()[1]);
        for(int i=1; i<Parametres::generationsMaxNb; i++){
            p.init();
            for(int i=1; i<Parametres::individualsNb; i++){
                p.mutate();
            }
            p.getEvolution().run();
        }
        createLine();
    }
}

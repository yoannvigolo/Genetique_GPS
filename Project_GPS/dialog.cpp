#include "dialog.h"
#include "ui_dialog.h"
#include "mapscene.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setWindowIcon(QIcon("map.png"));
    setWindowTitle("Information");
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_buttonBox_accepted()
{
    rueName = ui->lineEdit->text();

    if(!rueName.isEmpty()){
        informationRue += rueName;

        foreach (QPointF p, pointList) {
            informationRue +=";"+QString::number(p.x())+","+QString::number(p.y());
        }
    }

    else{
        QMessageBox::warning(this, "ERREUR", "Le nom inscrit n'est pas valide !");
    }

    Fichier::EditFile("C:/Users/yoann/OneDrive/Documents/qt_projects/Project_GPS/Rues/rueName.txt", informationRue.toStdString());
}

void Dialog::setPointList(const QList<QPointF> &value)
{
    pointList = value;
}


void Dialog::setLenghStreet(const qreal &value)
{
    lenghStreet = value;
}


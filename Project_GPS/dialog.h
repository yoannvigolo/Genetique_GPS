#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include "../GestionFichier/fichier.h"
#include <QIcon>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void setLenghStreet(const qreal &value);
    void setPointList(const QList<QPointF> &value);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;

    QString rueName;
    QString informationRue;
    qreal lenghStreet;

    QList<QPointF> pointList;
};

#endif // DIALOG_H

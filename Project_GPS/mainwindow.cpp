#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QGraphicsPixmapItem>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionQuitter->setIcon(QIcon("C:/Users/yoann/OneDrive/Documents/qt_projects/Project_GPS/logout.png"));
    ui->actionadd->setIcon(QIcon("C:/Users/yoann/OneDrive/Documents/qt_projects/Project_GPS/add.png"));

    setWindowTitle("Project GPS");
    setWindowIcon(QIcon("map.png"));

    m_scene = new mapScene(this);
    ui->graphicsView->setScene(m_scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

mapScene *MainWindow::getScene() const
{
    return m_scene;
}

void MainWindow::on_actionadd_triggered()
{
    Dialog* dial = new Dialog();
    dial->show();
}

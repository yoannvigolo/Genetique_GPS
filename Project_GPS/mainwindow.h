#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "mapscene.h"
#include <QImage>
#include <QPushButton>
#include "QMessageBox"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class mapScene;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    mapScene *getScene() const;

private slots:

    void on_actionadd_triggered();

private:
    Ui::MainWindow *ui;
    mapScene* m_scene;
    QLabel* label;
};
#endif // MAINWINDOW_H

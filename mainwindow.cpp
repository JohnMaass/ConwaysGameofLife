#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    grid = new Grid(new QGraphicsScene(this),ui->popLabel,ui->genLabel);
    ui->graphicsView->setScene(grid);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateCells()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCells()
{
    grid->updateCells();
    if(grid->allCellsDead)
        timer->stop();
}

void MainWindow::on_pushButton_clicked()
{

    timer->start(250);
}



void MainWindow::on_pushButton_2_clicked()
{
    timer->stop();
}
void MainWindow::on_pushButton_3_clicked()
{
    timer->stop();
    grid->resetCells();
}

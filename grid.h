#ifndef GRID_H
#define GRID_H

#include <QtCore>
#include <QGraphicsScene>
#include <QVector>
#include <QThread>
#include <QDebug>
#include <QLabel>
#include <QString>
#include "cell.h"

class Grid: public QGraphicsScene
{
public:
    Grid(QGraphicsScene *scene,QLabel *popLabel,QLabel *genLabel);
    QVector<Cell*> cells;
    void updateCells();
    void resetCells();


    QLabel *popLabel;
    QLabel *genLabel;
    bool allCellsDead;
    int generation;
    int population;

private:
    void updateLabels();
    void recountPopulation();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // GRID_H

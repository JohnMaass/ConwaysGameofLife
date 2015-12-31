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

    void updateCells();
    void resetCells();
    void clearCells();

    QVector<Cell*> cells;
    QVector<bool> seed;
    QLabel *popLabel;
    QLabel *genLabel;
    bool allCellsDead;
    int generation;
    int population;

private:
    void updateLabels();
    void recountPopulation();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setSeed();


};

#endif // GRID_H

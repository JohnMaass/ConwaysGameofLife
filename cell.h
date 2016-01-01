#ifndef CELL_H
#define CELL_H
#include <QtCore>
#include <QtGui>
#include <QVector>
#include <QGraphicsScene>
#include <QDebug>
#include <QPainter>
#include <QGraphicsItem>

class Cell: public QGraphicsItem
{
public:
    Cell(double x,double y);
    QRectF boundingRect() const;
    void addNeighbors(QVector<Cell*> *cells, int index);

    void determineNextState();
    void updateLifeState();
    void enableDraw();
    void disableDraw();
    int numNeighborsAlive();

    bool isAlive, aliveNextState,canDraw;
    double x,y;
    QVector<Cell*> neighbors;

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    void addNeighbors(QVector<Cell *> *cells, int r,int c,int upperBound);

};

#endif // CELL_H

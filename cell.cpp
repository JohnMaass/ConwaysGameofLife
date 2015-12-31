#include "cell.h"

Cell::Cell(double x, double y)
{
    isAlive=false;
    aliveNextState=false;
    this->x=x;
    this->y=y;
}

QRectF Cell::boundingRect() const
{
    return QRectF(x,y,5,5);
}



void Cell::addNeighbors(QVector<Cell *> *cells, int index)
{
    int upperBound = qSqrt(cells->size());
    int row=index/upperBound;
    int col=index%upperBound;

    if(col-1>-1){
        addNeighbors(cells,row,col-1,upperBound);
        if(row-1>-1){
            addNeighbors(cells,row-1,col-1,upperBound);
        }
        if(row+1<upperBound){
            addNeighbors(cells,row+1,col-1,upperBound);
        }

    }
    if(col+1<upperBound){
        addNeighbors(cells,row,col+1,upperBound);
        if(row-1>-1){
            addNeighbors(cells,row-1,col+1,upperBound);
        }
        if(row+1<upperBound){
            addNeighbors(cells,row+1,col+1,upperBound);
        }

    }
    if(row-1>-1){
         addNeighbors(cells,row-1,col,upperBound);
    }
    if(row+1<upperBound){
        addNeighbors(cells,row+1,col,upperBound);
    }
}

void Cell::determineNextState()
{
    int numAlive = numNeighborsAlive();
    if(numAlive==3){
         aliveNextState=true;
    }
    else if(numAlive<2){
        aliveNextState=false;
    }
    else if(numAlive==2 && isAlive){
        aliveNextState=true;
    }
    else{
        aliveNextState=false;
    }
}

void Cell::updateLifeState()
{
    isAlive=aliveNextState;
    //update();
}

int Cell::numNeighborsAlive()
{
    int numAlive=0;
    foreach(Cell *c, neighbors){
        if(c->isAlive){
            numAlive++;
        }
    }
    return numAlive;
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    if(isAlive){
        QBrush brush(Qt::black);
        painter->fillRect(rec,brush);
    }
    else{
        QBrush brush(Qt::white);
        painter->fillRect(rec,brush);
    }
    painter->drawRect(rec);
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
//    qDebug()<<neighbors.size();
    isAlive=!isAlive;
//    foreach(Cell *c, neighbors){
//        c->isAlive=!c->isAlive;
//        c->update();
//    }
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Cell::addNeighbors(QVector<Cell *> *cells, int r, int c, int upperBound)
{
    neighbors.append(cells->at((r*upperBound)+c));
}

#include "grid.h"

Grid::Grid(QGraphicsScene *scene,QLabel *popLabel,QLabel *genLabel):QGraphicsScene(scene)
{
    allCellsDead=false;
    generation=0;
    population=0;
    this->popLabel=popLabel;
    this->genLabel=genLabel;
    for(int i =-350;i<350;i+=5){
        for(int q =-350;q<350;q+=5){
            cells.append(new Cell(q,i));
            seed.append(false);
        }
    }
    for(int i=0;i<cells.size();i++){
        cells.at(i)->addNeighbors(&cells,i);
        this->addItem(cells.at(i));
    }
    updateLabels();
}

void Grid::updateCells()
{
    allCellsDead=true;
    if(population>0)
        generation++;
    foreach(Cell *c, cells){
        c->determineNextState();

    }
    foreach(Cell *c, cells){
        c->updateLifeState();
        if(c->isAlive){
            allCellsDead=false;

        }
    }
    updateLabels();
    update();
}

void Grid::resetCells()
{
    generation=0;

    for(int i = 0;i<cells.size();i++){
        cells.at(i)->isAlive=seed.at(i);
    }
    update();
    updateLabels();

}

void Grid::clearCells()
{
    generation=0;
    seed.clear();
    foreach(Cell *c, cells){
        c->isAlive=false;
        seed.append(false);
    }
    updateLabels();
    update();
}



void Grid::updateLabels()
{
    recountPopulation();

    popLabel->setText(QString("Population: %1").arg(population));
    genLabel->setText(QString("Generation: %1").arg(generation));
}

void Grid::recountPopulation()
{
    population=0;
    foreach(Cell *c,cells){
        if(c->isAlive)
            population++;
    }
}

void Grid::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    QGraphicsScene::mousePressEvent(event);
    updateLabels();
    setSeed();
}

void Grid::setSeed()
{
    seed.clear();
    foreach(Cell *c,cells){
        seed.append(c->isAlive);
    }
}



#include "dialogload.h"
#include "ui_dialogload.h"

DialogLoad::DialogLoad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLoad)
{
    ui->setupUi(this);
}

DialogLoad::~DialogLoad()
{
    delete ui;
}

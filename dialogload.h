#ifndef DIALOGLOAD_H
#define DIALOGLOAD_H

#include <QDialog>

namespace Ui {
class DialogLoad;
}

class DialogLoad : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLoad(QWidget *parent = 0);
    ~DialogLoad();

private:
    Ui::DialogLoad *ui;
};

#endif // DIALOGLOAD_H

#ifndef DEMO_H
#define DEMO_H

#include <QWidget>
#include "mygraphicsview.h"

namespace Ui {
class Demo;
}

class Demo : public QWidget
{
    Q_OBJECT

public:
    explicit Demo(QWidget *parent = nullptr);
    ~Demo();

private:
    Ui::Demo *ui;
};

#endif // DEMO_H

#include "demo.h"
#include "ui_demo.h"

Demo::Demo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demo)
{
    ui->setupUi(this);

    MyGraphicsView* view = new MyGraphicsView(this);

    ui->verticalLayout->addWidget(view);

}

Demo::~Demo()
{
    delete ui;
}


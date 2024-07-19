#include "tabwidget.h"
#include "ui_tabwidget.h"

tabWidget::tabWidget(QWidget *parent) :
    QTabWidget(parent),
     ui(new Ui::tabWidget)
{
    ui->setupUi(this);

    addTabs();



}

tabWidget::~tabWidget()
{
    delete ui;
}

void tabWidget::addTabs()
{
    ui->tWidget->addTab(new Theory(this), "Теория");
    ui->tWidget->addTab(new Demo(this), "Демонстрация");
}


void tabWidget::on_tWidget_tabBarClicked(int index)
{
    switch (index) {
    case 0: {
        std::cerr << "\n0";
    } break;
    case 1: {
        std::cerr << "\n1";
    } break;
    }
}


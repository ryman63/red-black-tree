#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include "theory.h"
#include "demo.h"
#include <iostream>

namespace Ui {
class tabWidget;
}

class tabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit tabWidget(QWidget *parent = nullptr);
    ~tabWidget();

    void addTabs();
private slots:

    void on_tWidget_tabBarClicked(int index);

private:
    Ui::tabWidget *ui;
signals:

};

#endif // TABWIDGET_H

#ifndef THEORY_H
#define THEORY_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QTabWidget>
#include <iostream>

namespace Ui {
class Theory;
}

class Theory : public QWidget
{
    Q_OBJECT

public:
    explicit Theory(QTabWidget *parent = nullptr);
    ~Theory();

private:
    Ui::Theory *ui;

    void fillLineEdit();
};

#endif // THEORY_H

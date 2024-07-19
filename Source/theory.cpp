#include "theory.h"
#include "ui_theory.h"

Theory::Theory(QTabWidget *parent) :
    QWidget(parent),
    ui(new Ui::Theory)
{
    ui->setupUi(this);
    fillLineEdit();
}

Theory::~Theory()
{
    delete ui;
}

void Theory::fillLineEdit()
{
    QFile file(QCoreApplication::applicationDirPath() + "/info.txt");

    if((file.exists()) && (file.open(QIODevice::ReadOnly)))
    {
        ui->textBrowser->setText(file.readAll());
        file.close();
    }
    else
    {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Warning);
        msg.setText("Файл info.txt отсутствует");
        msg.exec();
    }
}

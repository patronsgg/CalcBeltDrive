#include "viewresults.h"
#include "ui_viewresults.h"

viewResults::viewResults(std::vector<double> data, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewResults)
{
    ui->setupUi(this);
    for (size_t i = 0; i < data.size(); i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(data[i])));
    }
}

viewResults::~viewResults()
{
    delete ui;
}

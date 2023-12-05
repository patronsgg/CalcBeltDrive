#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Расчёт передачи");
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    std::vector<double> data;

    double p = ui->lineEdit->text().toDouble();
    double n = ui->lineEdit_2->text().toDouble();
    double u = ui->lineEdit_3->text().toDouble();

    if (p == 0 || n == 0 || u == 0) {
        qWarning("Невалидный ввод");
        return;
    }
    //1.
    double m = 3.5 * (pow((pow(10, 3) * p / n),(1/3.)));
    //2.
    double z_1 = mathbelt::returnZ(m, n);
    double z_2 = z_1 * u;
    //3.
    double d_1 = mathbelt::returnM(m) * z_1;
    double d_2 = mathbelt::returnM(m) * z_2;
    //4.
    double a = 0.5 * (d_1 + d_2) + 2 * mathbelt::returnM(m);
    double p_step = mathbelt::returnStep(mathbelt::returnM(m));
    double L_p = mathbelt::floorL(((2 * a) / (p_step)) + ((z_1 + z_2) / 2) + pow(((z_2 - z_1) / (2 * M_PI)), 2) * (p_step/a));
    //5.
    double a_final = (p_step/4) * (L_p - ((z_2 - z_1) / 2) + sqrt(pow(L_p -  (z_2 - z_1) / 2, 2) - 8 * pow((z_2 - z_1) / (2 * M_PI), 2)));
    //6.
    double alpha = 180 - (57 * (d_2 - d_1))/a_final;
    //7.
    double z_0 = z_1 * alpha / 360;
    if (z_0 >= 6) {
        qDebug() << "z_0 ok";
    }
    //8.
    double v = (M_PI * d_1 * n) / 60000;
    //9.
    double T_1  = 30 * p * 1000 / (M_PI * n);
    double F_t = 2 * T_1 * 1000 / d_1;
    //10. ??
    double F = mathbelt::returnF_0(mathbelt::returnM(m)) / 1.5 - mathbelt::returnQ(mathbelt::returnM(m)) * pow(v, 2);
    double b_non = F_t / F;
    double b = mathbelt::floorB(b_non / mathbelt::returnb(b_non));
    //11.
    double F_0 = mathbelt::returnF_y(mathbelt::returnM(m)) * b + mathbelt::returnQ(mathbelt::returnM(m)) * b * pow(v, 2);
    //12.
    double F_n = 1.1 * F_t;
    //13.
    double d_a1 =  d_1 - 2 * mathbelt::returnT(mathbelt::returnM(m)) + ((0.2 * mathbelt::returnLymbda(mathbelt::returnM(m)) * F_t * z_1) / b);
    double d_a2 =  d_2 - 2 * mathbelt::returnT(mathbelt::returnM(m)) + ((0.2 * mathbelt::returnLymbda(mathbelt::returnM(m)) * F_t * z_2) / b);

    double B = b + mathbelt::returnM(m);

    double p_s1 = (M_PI * (d_a1 - 4)) / z_1;
    double p_s2 = (M_PI * (d_a2 - 4)) / z_2;


    data.push_back(m);
    data.push_back(z_1);
    data.push_back(z_2);
    data.push_back(d_1);
    data.push_back(d_2);
    data.push_back(a);
    data.push_back(L_p);
    data.push_back(a_final);
    data.push_back(alpha);
    data.push_back(z_0);
    data.push_back(v);
    data.push_back(T_1);
    data.push_back(F_t);
    data.push_back(F);
    data.push_back(b_non);
    data.push_back(b);
    data.push_back(F_0);
    data.push_back(F_n);
    data.push_back(d_a1);
    data.push_back(d_a2);
    data.push_back(B);
    data.push_back(p_s1);
    data.push_back(p_s2);



    viewResults table(data);
    table.setModal(true);
    table.setWindowTitle("Итог расчёта");
    switch(table.exec()) {
    case QDialog::Rejected:
        return;
    }
}



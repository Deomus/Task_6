#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_clear->click();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// вычисления
void MainWindow::on_pushButton_result_clicked()
{
    // очищаем предыдущий результат
    ui->label_per_val->clear();
    ui->label_sqr_val->clear();
    ui->label_error->clear();

    // задаем новые значения
    x1 = ui->doubleSpinBox_x1->value();
    x2 = ui->doubleSpinBox_x2->value();
    x3 = ui->doubleSpinBox_x3->value();
    y1 = ui->doubleSpinBox_y1->value();
    y2 = ui->doubleSpinBox_y2->value();
    y3 = ui->doubleSpinBox_y3->value();

    // считаем периметр и площадь по формуле гаусса
    double perimeter = sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1)) + sqrt((x3-x2) * (x3-x2) + (y3-y2) * (y3-y2)) + sqrt((x1-x3) * (x1-x3) + (y1-y3) * (y1-y3));
    double square = abs((x2-x1) * (y3-y1) - (x3-x1) * (y2-y1)) / 2;

    // проверяем треугольник и выводим результат
    if (fabs(square) > 1e-7)
    {
        ui->label_per_val->setNum(perimeter);
        ui->label_sqr_val->setNum(square);
    }
    else
    {
        ui->label_error->setText("Треугольник на одной прямой");
        return;
    }
}

// очистка
void MainWindow::on_pushButton_clear_clicked()
{
    ui->label_per_val->clear();
    ui->label_sqr_val->clear();
    ui->label_error->clear();

    ui->doubleSpinBox_x1->setValue(0);
    ui->doubleSpinBox_x2->setValue(0);
    ui->doubleSpinBox_x3->setValue(0);
    ui->doubleSpinBox_y1->setValue(0);
    ui->doubleSpinBox_y2->setValue(0);
    ui->doubleSpinBox_y3->setValue(0);
}

// заполнение рандомными числами
void MainWindow::on_pushButton_random_clicked()
{
    ui->doubleSpinBox_x1->setValue(rand()%201-100);
    ui->doubleSpinBox_x2->setValue(rand()%201-100);
    ui->doubleSpinBox_x3->setValue(rand()%201-100);
    ui->doubleSpinBox_y1->setValue(rand()%201-100);
    ui->doubleSpinBox_y2->setValue(rand()%201-100);
    ui->doubleSpinBox_y3->setValue(rand()%201-100);
}

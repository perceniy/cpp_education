#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculateButton_clicked()
{
    QString str_a = ui->input_a->text();
    QString str_b = ui->input_b->text();
    QString str_c = ui->input_c->text();

    QString result;

    bool ok_a;
    bool ok_b;
    bool ok_c;

    int a = str_a.toInt(&ok_a , 10);
    int b = str_b.toInt(&ok_b , 10);
    int c = str_c.toInt(&ok_c , 10);;

    QString aString;
    if (ok_a & ok_b & ok_c) {
        double x1 = 0, x2 = 0;
        int D = 0;
        D = b*b - 4*a*c;
        if (D > 0) {
            x1 = (- static_cast<qreal>(b) + qSqrt(static_cast<qreal>(D)))/static_cast<qreal>(2*a);
            x2 = (- static_cast<qreal>(b) - qSqrt(static_cast<qreal>(D)))/static_cast<qreal>(2*a);
            result = "Solutions: ";
            result = result.append(QString::number(x1, 'g', 4));
            result = result.append("; ");
            result = result.append(QString::number(x2, 'g', 4));
            result = result.append(".");
            ui->solutions->setText(result);
        } else {
            ui->solutions->setText("D = 0");
        }
    } else {
        ui->solutions->setText("There is not real solutions.");
    }

}

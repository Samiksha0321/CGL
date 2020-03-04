
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
using namespace std;

int x1,y1;
int x2,y2;
int w=1;
QImage image(800,800,QImage::Format_RGB888);
QRgb green=qRgb(0,255,0);

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

void MainWindow::on_textEdit_textChanged()
{
    QString str = ui->textEdit->toPlainText();
    x1 = str.toInt();
}

void MainWindow::on_textEdit_2_textChanged()
{
    QString str = ui->textEdit_2->toPlainText();
    y1 = str.toInt();
}

void MainWindow::on_textEdit_3_textChanged()
{
    QString str = ui->textEdit_3->toPlainText();
    x2 = str.toInt();
}

void MainWindow::on_textEdit_4_textChanged()
{
    QString str = ui->textEdit_4->toPlainText();
    y2 = str.toInt();
}

void MainWindow::on_textEdit_5_textChanged()
{
    QString str = ui->textEdit_5->toPlainText();
    w = str.toInt();
}

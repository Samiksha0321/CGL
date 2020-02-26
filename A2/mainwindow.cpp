#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"math.h"
QImage img(1021,900,QImage :: Format_RGB888);
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
void MainWindow::on_pushButton_clicked()
{
    int x,y,R;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();
    R=ui->textEdit_3->toPlainText().toInt();
    ddaCIRCLE(x,y,R);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::dda(int x1, int y1, int x2, int y2)
{
    float dx=abs(x2-x1);
    float dy=abs(y2-y1);
    float p;
    float x=x1;
    float y=y1;
    int i=0;
    if(dx>=dy)
    {
        p=(2*dy)-dx;
        while(i<=dx)
        {
           img.setPixel(x,y,qRgb(255-i,i,255));
           ui->label->setPixmap(QPixmap::fromImage(img));
           if(p<0)
           {
               p=p+(2*dy);
           }
           else
           {
               p=p + (2*(dy-dx));
               y=y + (1*sign(y2,y1));
           }
           x=x + (1*sign(x2,x1));
           i++;
        }
    }
    else
    {
        p=(2*dx)-dy;
        while(i<=dy)
        {
           img.setPixel(x,y,qRgb(255-i,i,255));
           ui->label->setPixmap(QPixmap::fromImage(img));
           if(p<0)
           {
               p=p+(2*dx);
           }
           else
           {
               p=p + (2*(dx-dy));
               x=x + (1*sign(x2,x1));
           }
           y=y + (1*sign(y2,y1));
           i++;
        }

    }
 }
int MainWindow::sign(int x1, int x2)
    {
        int a= x1-x2;
        if(a>0)
            return 1;
        if(a<0)
            return -1;
        if(a==0)
            return 0;

        return -2;
    }
void MainWindow::draw(int xc, int yc, int x, int y)
    {
        int i=67;
        img.setPixel(xc+x,yc+y,qRgb(255-i,i,255));
        img.setPixel(xc+y,yc+x,qRgb(255-i,i,255));
        img.setPixel(xc-y,yc+x,qRgb(255-i,i,255));
        img.setPixel(xc-x,yc+y,qRgb(255-i,i,255));
        img.setPixel(xc-x,yc-y,qRgb(255-i,i,255));
        img.setPixel(xc-y,yc-x,qRgb(255-i,i,255));
        img.setPixel(xc+y,yc-x,qRgb(255-i,i,255));
        img.setPixel(xc+x,yc-y,qRgb(255-i,i,255));
        ui->label->setPixmap(QPixmap::fromImage(img));
    }
void MainWindow::ddaCIRCLE(int xc, int yc, int R)
{

    int i=67;
    float x1=R;
    float y1=0;
    float e= 1.0/R;
    float x2,y2;
    do
    {
        x2=x1 + (e*y1);
        y2=y1 - (e*x2);
         img.setPixel(xc+x2,yc-y2,qRgb(255-i,255,255-i));
         ui->label->setPixmap(QPixmap::fromImage(img));
         x1=x2;
         y1=y2;
         i++;
    }while((y1<e)||(R-x1)>e);

}
void MainWindow::bCIRCLE(int xc, int yc, int R)
{

    float x=0;
    float y=R;
    float p=3-(2*R);
    while(x<=y)
    {
        draw(xc,yc,x,y);
        if(p<0)
        {
            p=p+(4*x)+6;
        }
        else
        {
            p=p+(4*(x-y))+10;
            y=y-1;
        }
        x=x+1;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int x,y,R;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();
    R=ui->textEdit_4->toPlainText().toInt();
    bCIRCLE(x,y,R);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_3_clicked()
{
    int x,y,R;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();
    R=ui->textEdit_4->toPlainText().toInt();

    float x1=x;
    float y1=y-R;

    float x2=x-(0.866025404*R);
    float y2=y+(R/2);

    float x3=x+(0.866025404*R);
    float y3=y+(R/2);

    dda(x1,y1,x2,y2);
    dda(x2,y2,x3,y3);
    dda(x3,y3,x1,y1);
      ui->label->setPixmap(QPixmap::fromImage(img));



}

void MainWindow::on_pushButton_4_clicked()
{
    bCIRCLE(200,200,100);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ddaCIRCLE(200,200,50);
    ui->label->setPixmap(QPixmap::fromImage(img));

    float x1=200;
    float y1=200-100;

    float x2=200-(0.866025404*100);
    float y2=200+(100/2);

    float x3=200+(0.866025404*100);
    float y3=200+(100/2);

    dda(x1,y1,x2,y2);
    dda(x2,y2,x3,y3);
    dda(x3,y3,x1,y1);
      ui->label->setPixmap(QPixmap::fromImage(img));


}

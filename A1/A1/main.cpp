#include "mainwindow.h"
#include <QApplication>
#include<QtGui>

QImage DDA(int x1, int y1, int x2, int y2, QImage image,QRgb value)
{
    int dx, dy, skp, xinc, yinc, x, y;
    dx = x2-x1;
    dy = y2-y1;

    if( abs(dx) > abs(dy))
            skp = abs(dx);
    else
            skp = abs(dy);

    xinc = dx/skp;
    yinc = dy/skp;

    x=x1;
    y=y1;

    for(int i=0; i<=skp; i++)
    {
        image.setPixel(x, y, value);
        x+=xinc;
        y+=yinc;
    }
    return image;
}

QImage Bresenhams(int x1, int y1, int x2, int y2, QImage image,QRgb value)
{
    int dx, dy, temp, interchange, x, y;
    Sign s1, s2;
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    x=x1;
    y=y1;
    s1 = Sign(x2-x1);
    s2 = Sign(y2-y1);

    if(dy>dx)
    {
        temp = dx;
        dx = dy;
        dy = temp;
        interchage=1;
    }
    else
        interchange=0;
    return image;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QImage image(300, 300, QImage::Format_RGB888);
    QRgb value;
    value=qRgb(0,255,0);   //set color of pixel as green

    //diamond using DDA
    image = DDA(50, 150, 150, 50, image, value);
    image = DDA(150, 50, 250, 150, image, value);
    image = DDA(250, 150, 150, 250, image, value);
    image = DDA(150, 250, 50, 150, image, value);

    //outer square
    image = Bresenhams(50, 50, 250, 50, image, value);
    image = Bresenhams(250, 50, 250, 250, image, value);
    image = Bresenhams(250, 250, 50, 250, image, value);
    image = Bresenhams(50, 250, 50, 50, image, value);

    QLabel l;                              //shows pixel on screen
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    return a.exec();
}

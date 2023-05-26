#include "ekran.h"
#include <QPainter>
#include <QMouseEvent>
#include <cstdio>
#include <cstdlib>
#include <cmath>


Ekran::Ekran(QWidget *parent)
    : QWidget{parent}
{
    im=QImage(1000, 1000, QImage::Format_RGB32);
    im.fill(0);
}

void Ekran::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawImage(0,0,im);
}

void Ekran::mouseMoveEvent(QMouseEvent *e)
{
    p2.x=e->pos().x();
    p2.y=e->pos().y();
    for(auto k:vector)
    {
        drawPixel(k.x,k.y,k.red,k.green,k.blue);
    }
    vector.clear();
    if(abs(p2.y-p1.y)<=abs(p2.x-p1.x))
    {
        float y=p1.y;
        float a=(float)(p2.y-p1.y)/(p2.x-p1.x);
        if(p1.x<p2.x)
        {
            for(int i=p1.x;i<=p2.x;i++)
            {
                drawPixel(i+0.5,y+0.5,255,255,255);
                y+=a;
            }
        }
        else
        {
            for(int i=p1.x;i>=p2.x;i--)
            {
                drawPixel(i+0.5,y+0.5,255,255,255);
                y-=a;
            }
        }

    }
    else
    {
        float x=p1.x;
        float a=(float)(p1.x-p2.x)/(p1.y-p2.y);
        if(p1.y<p2.y)
        {
            for(int i=p1.y;i<=p2.y;i++)
            {
                drawPixel(x+0.5,i+0.5,255,255,255);
                x+=a;
            }
        }
        else
        {
            for(int i=p1.y;i>=p2.y;i--)
            {
                drawPixel(x+0.5,i+0.5,255,255,255);
                x-=a;
            }
        }
    }
    update();
}

void Ekran::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        vector.clear();
        p1.x=e->pos().x();
        p1.y=e->pos().y();
    }
}

void Ekran::drawPixel(int x,int y,int r,int g,int b)
{
    colorAtPixel k;
    if((x<im.width()&&x>=0)&&(y<im.height()&&y>=0))
    {
        QColor color(im.pixel(x, y));
        k.x=x;
        k.y=y;
        k.red=color.red();
        k.green=color.green();
        k.blue=color.blue();
        vector.push_back(k);
        uchar *pix=im.scanLine(y)+4*x;
        pix[0]=r;
        pix[1]=g;
        pix[2]=b;
    }

}

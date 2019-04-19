#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "linedrawing.h"

LineDrawing::LineDrawing()
{

}
QImage img=QImage(500,500,QImage::Format_RGB888);

void LineDrawing::dda(float x1,float y1,float x2,float y2)
{
    QRgb val=qRgb(255,0,0);
    float dx=x2-x1,dy=y2-y1,steps;
    steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
    float xinc=dx/steps,yinc=dy/steps;
    float x=x1+0.5*sign(dx),y=y1+0.5*sign(dy);
    for(int i=0;i<=steps;i++)
    {
if(i%12==5 || i%12==7)
{
    x+=xinc;
    y+=yinc;
    continue;
}
      img.setPixel(x,y,val);

       x+=xinc;
       y+=yinc;
    }

}

void LineDrawing::bres(int x1,int y1,int x2,int y2,int f)
{
    QRgb val=qRgb(0,255,0);
    int inte=0,dy=abs(y2-y1),dx=abs(x2-x1);
    int sx=sign(x2-x1),sy=sign(y2-y1);
    if(dy>dx)
    {
        inte=1;
        int temp=dy;
        dy=dx;
        dx=temp;
    }
    int e=2*dy-dx;
    int x=x1,y=y1;
    for(int i=0;i<dx;i++)
    {
        if(i%f==0)
        {img.setPixel(x,y,val);}
        while(e>=0)
        {
            if(inte)
            {
                x+=sx;
            }
            else
            {
                y+=sy;
            }
            e-=2*dx;
        }
        if(inte)
        {
            y+=sy;
        }
        else
        {
            x+=sx;
        }
        e+=2*dy;
    }

}

int LineDrawing::sign(int x)
{
    if(x==0)
    {
        return 0;
    }
    if(x>0)
    {
        return 1;
    }
    return -1;
}
QImage LineDrawing::getimage()
{
    return img;
}

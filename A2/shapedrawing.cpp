#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shapedrawing.h"
#include"math.h"
ShapeDrawing::ShapeDrawing()
{

}

QImage img=QImage(500,500,QImage::Format_RGB888);
void ShapeDrawing::bres(int x1,int y1,int x2,int y2)
{
    QRgb val=qRgb(0,0,255);
    int dx,dy,inte=0,x=x1,y=y1,sx,sy,e;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    sx=sign(x2-x1);
    sy=sign(y2-y1);
    if(dy>dx)
    {
        int temp=dy;
        dy=dx;
        dx=temp;
        inte=1;
    }
    e=2*dy-dx;
    for(int i=0;i<dx;i++)
    {
        img.setPixel(x,y,val);
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
int ShapeDrawing::sign(int x)
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
QImage ShapeDrawing::getimage()
{
    return img;

}

void ShapeDrawing::ddac(int xc,int yc,int r)
{
    QRgb value=qRgb(0,0,255);
    float x1=r,y1=0,e,sx=x1,sy=y1,y2,x2;
    int i=0,val;
    do
    {
        val=pow(2,i);
        i++;
    }while(val<r);
e=1/pow(2,i-1);
do
{
    x2=x1+e*y1;
    y2=y1-e*x2;
    img.setPixel(xc+x2,yc-y2,value);
    x1=x2;
    y1=y2;

}while((y1-sy<e) || sx-x1>e);


}




void ShapeDrawing::bcircle(int xc,int yc,int r)
{
    int x=0,y=r,s=3-2*r;
    QRgb val=qRgb(0,255,0);
    while(y>=x)
    {
        draw(xc,yc,x,y);
       if(s<=0)
       {
           s=s+4*x+6;
       }
       else
       {
           s=s+4*(x-y)+10;
           y--;
       }
       x++;

}

}





void ShapeDrawing::draw(int x,int y,int x1,int y1)
{
    QRgb val=qRgb(255,0,0);

    img.setPixel(x+x1,y+y1,val);
    img.setPixel(x-x1,y+y1,val);
    img.setPixel(x+x1,y-y1,val);
    img.setPixel(x-x1,y-y1,val);
    img.setPixel(x+y1,y+x1,val);
    img.setPixel(x-y1,y+x1,val);
    img.setPixel(x+y1,y-x1,val);
    img.setPixel(x-y1,y-x1,val);
}

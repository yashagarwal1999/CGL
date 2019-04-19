#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QMouseEvent"""
#include "QtDebug"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ver=0;
    start=true;


}
QImage img=QImage(500,500,QImage::Format_RGB888);
void MainWindow::dda(int x1,int y1,int x2,int y2)
{
    QRgb val=qRgb(0,255,0);
    float dx=(x2-x1),dy=(y2-y1);
    float x=x1+0.5*sign(dx),y=y1+0.5*sign(y2-y1),steps;
    steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
    float xinc=dx/steps,yinc=dy/steps;
    for(int i=0;i<=steps;i++)
    {
        img.setPixel(x-7,y+40,val);
        x+=xinc;
        y+=yinc;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    int p=ev->pos().x();
    int q=ev->pos().y();
    a[ver]=p;
    b[ver]=q;
    if(start)
    {

        if(ev->button()==Qt::RightButton)
        {
            dda(a[ver],b[ver],a[0],b[0]);
            start=false;

        }
        else
        {
            if(ver>0)
            {
                dda(a[ver],b[ver],a[ver-1],b[ver-1]);

            }
        }

    }
    ver++;
}

int MainWindow::sign(int x)
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

MainWindow::~MainWindow()
{
    delete ui;
}

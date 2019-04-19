#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"cmath"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QRgb val=qRgb(0,255,0);
    bres(0,250,0,-250,val);
    bres(-250,0,250,0,val);


}
const int X1=330-250,Y1=250-130,X2=270-250,Y2=250-200,X3=400-250,Y3=250-200;
const float rad=3.141/180.0;
MainWindow::~MainWindow()
{
    delete ui;
}
QImage img=QImage(500,500,QImage::Format_RGB888);
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

void MainWindow::bres(int x1,int y1,int x2,int y2,QRgb val)
{
    int dx=x2-x1,dy=y2-y1,sx=sign(dx),sy=sign(dy);
    int inte=0,e;
    int x=x1,y=y1;
    dx=abs(dx);
    dy=abs(dy);
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
         img.setPixel(x+250,250-y,val);
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

ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_clicked()
{
     QRgb val=qRgb(0,255,0);
    bres(X1,Y1,X2,Y2,val);
    bres(X1,Y1,X3,Y3,val);
    bres(X2,Y2,X3,Y3,val);

    int a[3][2]={{X1,Y1},{X2,Y2},{X3,Y3}};
    int b[2][2]={{1,0},{0,-1}};
    mul(a,b);

 QRgb v=qRgb(255,0,0);
 bres(a[0][0],a[0][1],a[1][0],a[1][1],v);
 bres(a[1][0],a[1][1],a[2][0],a[2][1],v);
 bres(a[0][0],a[0][1],a[2][0],a[2][1],v);

}

void MainWindow::mul(int a[3][2],int b[2][2])
{
int res[3][2];
for(int i=0;i<3;i++)
{
for(int j=0;j<2;j++)
{
res[i][j]=0;
for(int k=0;k<2;k++)
{
res[i][j]+=a[i][k]*b[k][j];
}
}
}
for(int i=0;i<3;i++)
{
for(int j=0;j<2;j++)
{

a[i][j]=res[i][j];
}

}
}


void MainWindow::muld(double a[3][2],double b[2][2])
{
double res[3][2];
for(int i=0;i<3;i++)
{
for(int j=0;j<2;j++)
{
res[i][j]=0;
for(int k=0;k<2;k++)
{
res[i][j]+=a[i][k]*b[k][j];
}
}
}
for(int i=0;i<3;i++)
{
for(int j=0;j<2;j++)
{

a[i][j]=res[i][j];
}

}
}

void MainWindow::on_pushButton_2_clicked()
{
    QRgb val=qRgb(0,255,0);
   bres(X1,Y1,X2,Y2,val);
   bres(X1,Y1,X3,Y3,val);
   bres(X2,Y2,X3,Y3,val);

   int a[3][2]={{X1,Y1},{X2,Y2},{X3,Y3}};
   //int b[2][2]={{1,0},{0,-1}};
   int b[2][2]={{-1,0},{0,1}};
   mul(a,b);

QRgb v=qRgb(0,0,255);
bres(a[0][0],a[0][1],a[1][0],a[1][1],v);
bres(a[1][0],a[1][1],a[2][0],a[2][1],v);
bres(a[0][0],a[0][1],a[2][0],a[2][1],v);
}

void MainWindow::on_pushButton_3_clicked()
{
    QRgb val=qRgb(0,255,0);
   bres(X1,Y1,X2,Y2,val);
   bres(X1,Y1,X3,Y3,val);
   bres(X2,Y2,X3,Y3,val);

   int a[3][2]={{X1,Y1},{X2,Y2},{X3,Y3}};
   //int b[2][2]={{1,0},{0,-1}};
   int b[2][2]={{0,1},{1,0}};
   mul(a,b);

   QRgb v=qRgb(255,0,255);
   bres(a[0][0],a[0][1],a[1][0],a[1][1],v);
   bres(a[1][0],a[1][1],a[2][0],a[2][1],v);
   bres(a[0][0],a[0][1],a[2][0],a[2][1],v);

}

void MainWindow::on_pushButton_4_clicked()
{
    int x,y,theta;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();
    theta=ui->textEdit_3->toPlainText().toInt();

    QRgb val=qRgb(0,255,0);
   bres(X1,Y1,X2,Y2,val);
   bres(X1,Y1,X3,Y3,val);
   bres(X2,Y2,X3,Y3,val);

    int a=X1-x,b=Y1-y,c=X2-x,d=Y2-y,e=X3-x,f=Y3-y;
     double A[3][2]={{a,b},{c,d},{e,f}};
     QRgb v=qRgb(0,35,255);
     bres(A[0][0],A[0][1],A[1][0],A[1][1],v);
     bres(A[1][0],A[1][1],A[2][0],A[2][1],v);
     bres(A[0][0],A[0][1],A[2][0],A[2][1],v);
     float C=rad*theta;
     double B[2][2]={{(cos(C)),(sin(C))},{(-1*sin(C)),(cos(C))}};
     muld(A,B);
     for(int i=0;i<3;i++)
     {
         A[i][0]+=x;
         A[i][1]+=y;
     }
      v=qRgb(255,35,255);
     bres(A[0][0],A[0][1],A[1][0],A[1][1],v);
     bres(A[1][0],A[1][1],A[2][0],A[2][1],v);
     bres(A[0][0],A[0][1],A[2][0],A[2][1],v);
}

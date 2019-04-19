#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include<math.h>
#include<queue>
#include<cstdlib>
using namespace std;
queue<int> q;
static QImage img(400,400,QImage::Format_RGB888);
static int a[10], b[10], ver=0,sx,sy;
static bool start;


void axes(){
    for(int i=0;i<400;i++){
        img.setPixel(i,200,qRgb(255,255,255));
        img.setPixel(200,i,qRgb(255,255,255));

    }
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
    axes();

}

MainWindow::~MainWindow()
{
    delete ui;
}

int sign(int a){
    if(a<0)
        return -1;
    else if(a>0)
        return 1;
    else return 0;

}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(ev->pos().x()>400 || ev->pos().y()>400)
        return;

    if(start==true)
    {
    int p1=ev->pos().x();
    int p2=ev->pos().y();

    if(ver==0){
        sx=p1; sy=p2;
    }

     if(ev->button()==Qt::RightButton)
     {
         a[ver]=p1;
         b[ver]=p2;
         dda(sx,sy,a[ver],b[ver]);
         dda(a[ver-1],b[ver-1],a[ver],b[ver]);
         start=false;

     }
     else {
         a[ver]=p1;
         b[ver]=p2;
         if(ver>0)
         {
             dda(a[ver],b[ver],a[ver-1],b[ver-1]);
         }else{
             sx=p1;
             sy=p2;

             dda(sx,sy,sx,sy);

         }

     }
     ver++;
    }
  }

void MainWindow::dda(int x1,int y1,int x2,int y2)
{

    float x,y,dx,dy,l,i=1;
    QRgb value;
    value=qRgb(0,255,0);

    l=std::abs(x2-x1)>std::abs(y2-y1)?std::abs(x2-x1):std::abs(y2-y1);
    dx=(x2-x1)/l;
    dy=(y2-y1)/l;

    x=x1+0.5f;
    y=y1+0.5f;
    do
    {
       img.setPixel(static_cast<int>(x),static_cast<int>(y),value);
       x = x + dx;
       y = y + dy;
       i++;
      }while(i <= l);


ui->label->setPixmap(QPixmap::fromImage(img));

}

void clear(){
    img.fill(qRgb(0,0,0));
}


void MainWindow::on_pushButton_2_clicked()
{
    clear();
    axes();
    int t1[ver],t2[ver];
    if(start == true)
        return;
    float theta = ui->spinBox->text().toFloat();
    theta = theta * 3.14 / 180;

    for(int i=0;i<ver;i++){
       int x=a[i] - 200;
       int y=200 - b[i];
          t1[i]  = x*cos(theta) -y*sin(theta);
          t2[i]  = x*sin(theta) +y*cos(theta);
    }
     for(int i=0;i<ver-1;i++){

       dda(t1[i]+200,200-t2[i],t1[i+1]+200,200-t2[i+1]);

    }
    dda(t1[0]+200,200-t2[0],t1[ver-1]+200,200-t2[ver-1]);



}
void MainWindow::on_pushButton_4_clicked()
{
    clear();
    axes();
    start=true;
    ui->label->setPixmap(QPixmap::fromImage(img));
    ver=0;
}

void MainWindow::on_scale_clicked()
{

    int t1[ver],t2[ver];
    if(start == true)
        return;
    float theta = ui->doubleSpinBox->text().toFloat();

    for(int i=0;i<ver;i++){
       int x=a[i] - 200;
       int y=200 - b[i];
          t1[i]  = x*theta;
          t2[i]  = y*theta;
    }
     for(int i=0;i<ver-1;i++){

       dda(t1[i]+200,200-t2[i],t1[i+1]+200,200-t2[i+1]);

    }
    dda(t1[0]+200,200-t2[0],t1[ver-1]+200,200-t2[ver-1]);
}

void MainWindow::on_translate_clicked()
{
    int t1[ver],t2[ver];
    if(start == true)
        return;
    int x1 = ui->lineEdit->text().toInt();
    int y1 = ui->lineEdit_2->text().toInt();

    for(int i=0;i<ver;i++){
       int x=a[i] - 200;
       int y=200 - b[i];
          t1[i]  = x + x1;
          t2[i]  = y + y1;
    }
     for(int i=0;i<ver-1;i++){

       dda(t1[i]+200,200-t2[i],t1[i+1]+200,200-t2[i+1]);

    }
    dda(t1[0]+200,200-t2[0],t1[ver-1]+200,200-t2[ver-1]);
}

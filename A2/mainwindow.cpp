#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"shapedrawing.h"
#include"bits/stdc++.h"
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
    int x,y,r;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_3->toPlainText().toInt();
    ShapeDrawing s;
    float a=0.866;
    s.bcircle(x,y,r);
    s.bres(x,y-r,x-a*r,y+0.5*r);
    s.bres(x,y-r,x+a*r,y+0.5*r);
    s.bres(x-a*r,y+0.5*r,x+a*r,y+0.5*r);
    s.ddac(x,y,r/2);
    ui->label->setPixmap(QPixmap::fromImage(s.getimage()));

}

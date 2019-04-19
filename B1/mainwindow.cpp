#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"linedrawing.h"
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
   float x1,y1,x2,y2;
   x1=ui->textEdit->toPlainText().toFloat();
   y1=ui->textEdit_2->toPlainText().toFloat();
   x2=ui->textEdit_3->toPlainText().toFloat();
   y2=ui->textEdit_4->toPlainText().toFloat();
   LineDrawing l;
   l.bres(x1,y1,x2,y2,1);
   ui->label->setPixmap(QPixmap::fromImage(l.getimage()));
}



void MainWindow::on_pushButton_2_clicked()
{
    float x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    LineDrawing l;
    l.bres(x1,y1,x2,y2,4);
    ui->label->setPixmap(QPixmap::fromImage(l.getimage()));


}

void MainWindow::on_pushButton_4_clicked()
{
    float x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    LineDrawing l;
    l.bres(x1,y1,x2,y2,2);
    ui->label->setPixmap(QPixmap::fromImage(l.getimage()));
}

void MainWindow::on_pushButton_3_clicked()
{
    float x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    LineDrawing l;
    l.bres(x1,y1,x2,y2,1);

    l.bres(x1+1,y1,x2+1,y2,1);
l.bres(x1+2,y1,x2+2,y2,1);


    ui->label->setPixmap(QPixmap::fromImage(l.getimage()));


}

void MainWindow::on_pushButton_5_clicked()
{
    float x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    LineDrawing l;
    l.dda(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(l.getimage()));
}

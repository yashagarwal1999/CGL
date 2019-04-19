#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
int sign(int x);
void dda(int x1,int y1,int x2,int y2);
void mousePressEvent(QMouseEvent *ev);

private:
    Ui::MainWindow *ui;
    bool start;
    int a[100],b[100];
    int ver;
};

#endif // MAINWINDOW_H

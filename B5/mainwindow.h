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

    void hilbert(int u,int r,int d, int l, int h,int i,int& x,int& y);
    void dda( float x1, float y1, float x2, float y2);
    void move( int j, int h, int&x, int &y);
    int sign(int x);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

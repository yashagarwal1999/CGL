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
    void mousePressEvent(QMouseEvent *ev);
    void dda(int x1,int y1,int x2,int y2);



private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_scale_clicked();

    void on_translate_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

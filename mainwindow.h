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

private slots:
    void on_pushButton_clicked();

    void on_btnnext_clicked();

    void on_btnpreviews_clicked();

    void on_viewbutton1_clicked();

    void on_btnviewcancel_clicked();

    void on_viewbutton2_clicked();

    void on_viewbutton3_clicked();

    void on_viewbutton4_clicked();

private:
    Ui::MainWindow *ui;
    int offset;
    int bookidviews1;
    int bookidviews2;
    int bookidviews3;
    int bookidviews4;

};

#endif // MAINWINDOW_H

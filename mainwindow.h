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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double x1, y1, x2, y2, x3, y3;

private slots:
    void on_pushButton_clear_clicked();

    void on_pushButton_result_clicked();

    void on_pushButton_random_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton7_clicked();

    void on_pushButton8_clicked();

    void on_pushButton9_clicked();

    void on_pushButtonC_clicked();

    void on_pushButton4_clicked();

    void on_pushButton5_clicked();

    void on_pushButton6_clicked();

    void on_pushButtonMinus_clicked();

    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void on_pushButtonPlus_clicked();

    void on_pushButtonMultiply_clicked();

    void on_pushButton0_clicked();

    void on_pushButtonDivide_clicked();

    void on_pushButtonResult_clicked();

private:
    void updateText();

    Ui::MainWindow *ui;
    QString left;
    QString right;
    QString action;
};
#endif // MAINWINDOW_H

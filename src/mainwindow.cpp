#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace
{

QString toEmoji(const QString& text_)
{
    QString text;

    for (const QChar& c : text_)
    {
        if (c == '0')
        {
            text += "😮";
        }
        else if (c == '1')
        {
            text += "😀";
        }
        else if (c == '2')
        {
            text += "😉";
        }
        else if (c == '3')
        {
            text += "😁";
        }
        else if (c == '4')
        {
            text += "😆";
        }
        else if (c == '5')
        {
            text += "😅";
        }
        else if (c == '6')
        {
            text += "😂";
        }
        else if (c == '7')
        {
            text += "🤣";
        }
        else if (c == '8')
        {
            text += "😊";
        }
        else if (c == '9')
        {
            text += "🙂";
        }
        else if (c == '+')
        {
            text += "😎";
        }
        else if (c == '-')
        {
            text += "🧐";
        }
        else if (c == '/')
        {
            text += "🥸";
        }
        else if (c == 'x')
        {
            text += "🥳";
        }
        else if (c == '.' || c == ',')
        {
            text += "🙃";
        }
        else if (c == 'e' || c == 'E')
        {
            text += "😱";
        }
        else
        {
            text += c;
        }
    }

    return text;
}

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateText();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton7_clicked()
{
    if (action.isEmpty())
    {
        left += "7";
    }
    else
    {
        right += "7";
    }

    updateText();
}

void MainWindow::on_pushButton8_clicked()
{
    if (action.isEmpty())
    {
        left += "8";
    }
    else
    {
        right += "8";
    }

    updateText();
}

void MainWindow::on_pushButton9_clicked()
{
    if (action.isEmpty())
    {
        left += "9";
    }
    else
    {
        right += "9";
    }

    updateText();
}

void MainWindow::on_pushButtonC_clicked()
{
    left.clear();
    right.clear();
    action.clear();
    updateText();
}

void MainWindow::on_pushButton4_clicked()
{
    if (action.isEmpty())
    {
        left += "4";
    }
    else
    {
        right += "4";
    }

    updateText();
}

void MainWindow::on_pushButton5_clicked()
{
    if (action.isEmpty())
    {
        left += "5";
    }
    else
    {
        right += "5";
    }

    updateText();
}

void MainWindow::on_pushButton6_clicked()
{
    if (action.isEmpty())
    {
        left += "6";
    }
    else
    {
        right += "6";
    }

    updateText();
}

void MainWindow::on_pushButtonMinus_clicked()
{
    if (left.isEmpty())
    {
        return;
    }

    action = "-";
    updateText();
}

void MainWindow::on_pushButton1_clicked()
{
    if (action.isEmpty())
    {
        left += "1";
    }
    else
    {
        right += "1";
    }

    updateText();
}


void MainWindow::on_pushButton2_clicked()
{
    if (action.isEmpty())
    {
        left += "2";
    }
    else
    {
        right += "2";
    }

    updateText();
}

void MainWindow::on_pushButton3_clicked()
{
    if (action.isEmpty())
    {
        left += "3";
    }
    else
    {
        right += "3";
    }

    updateText();
}

void MainWindow::on_pushButtonPlus_clicked()
{
    if (left.isEmpty())
    {
        return;
    }

    action = "+";
    updateText();
}

void MainWindow::on_pushButtonMultiply_clicked()
{
    if (left.isEmpty())
    {
        return;
    }

    action = "x";
    updateText();
}

void MainWindow::on_pushButton0_clicked()
{
    if (action.isEmpty())
    {
        left += "0";
    }
    else
    {
        right += "0";
    }

    updateText();
}

void MainWindow::on_pushButtonDivide_clicked()
{
    if (left.isEmpty())
    {
        return;
    }

    action = "/";
    updateText();
}

void MainWindow::on_pushButtonResult_clicked()
{
    bool ok = false;
    const long long int leftNum = left.toULongLong(&ok);
    if (!ok)
    {
        return;
    }

    const long long int rightNum = right.toULongLong(&ok);
    if (!ok)
    {
        return;
    }

    double result = 0;

    if (action == "+")
    {
        result = leftNum + rightNum;
    }
    else if (action == "-")
    {
        result = leftNum - rightNum;
    }
    else if (action == "/")
    {
        result = leftNum / (double)rightNum;
    }
    else if (action == "x")
    {
        result = leftNum * (double)rightNum;
    }
    else
    {
        return;
    }

    action.clear();

    ui->textBrowserResult->setText(toEmoji(QString().number(result)));

    left.clear();
    right.clear();
    action.clear();
}

void MainWindow::updateText()
{
    QString text;

    if (!left.isEmpty())
    {
        text += left;
        text += "\n\r";
    }

    if (!action.isEmpty())
    {
        text += action;
        text += "\n\r";
    }

    if (!right.isEmpty())
    {
        text += right;
    }

    ui->textBrowserResult->setText(toEmoji(text));
}

﻿#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

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

public:
    Q_SIGNAL void justRun(const QString &);

private slots:
    void on_selectButton_clicked();
    void on_doButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP



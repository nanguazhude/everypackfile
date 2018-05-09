#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_selectButton_clicked(){
    const QString var = QFileDialog::getExistingDirectory();
    if( var.isEmpty() ){ return ; }
    ui->dirName->setText( var );
}

void MainWindow::on_doButton_clicked(){
    const QString var = ui->dirName->text();
    if( var.isEmpty() ){ return ; }
    justRun( var );
}


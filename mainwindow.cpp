#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextStream>
#include <QFile>
#include <QByteArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ComposeFile(const QString& datass)
{
    QFile f1("data/dataA.txt");
    QFile f2(datass);

    //Kiem tra viec doc
    if(f1.open(QIODevice::ReadOnly) && f2.open(QIODevice::ReadOnly)){ // doc dong thoi 2 file
        QByteArray dataf1 = f1.readAll();
        QByteArray dataf2 = f2.readAll();

        if( dataf1 == dataf2 ){
            ui->RetureF->setText("Hai File giong nhau");
        }else {
            ui->RetureF->setText("Hai File khac nhau");
       }
        f1.close();
        f2.close();
    }
}

void MainWindow::on_pushButton_clicked()
{
    QFile file("data/dataB.txt");

     QString SaDataF2 = ui->editF2->text();
    //QTextStream TextStream(&file);
      //  TextStream >> SaDataF2;
    if(file.open(QIODevice::WriteOnly| QIODevice::Text)){
       QTextStream stream(&file); //
       stream << SaDataF2;
       file.close();
    }
    ui->dataF2->setText(SaDataF2);

    ComposeFile("data/dataB.txt");
}


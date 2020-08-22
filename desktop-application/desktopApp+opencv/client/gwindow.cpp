#include "gwindow.h"
#include "ui_gwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;
gWindow::gWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gWindow)
{
    ui->setupUi(this);

    // Initialize the second window
    mainwindow = new MainWindow();


    ui->label->setAlignment(Qt::AlignCenter);
    // connected to the slot start the main window on the button in the second window
    connect(mainwindow, &MainWindow::show, this,  &gWindow::firstWindow);
    dataTimer = new QTimer(this);
    connect(dataTimer, SIGNAL(timeout()), this, SLOT(loading()));
    dataTimer->start(100);
}

gWindow::~gWindow()
{
    delete ui;

}

void gWindow::loading()
{
    if(loadLabelNumber == 0){
        ui->loadingLabel->setText("\t\t\t   Connecting to server");

    }else if(loadLabelNumber == 1){
         ui->loadingLabel->setText("\t\t\t   Connecting to server .");

    }else if(loadLabelNumber == 2){
         ui->loadingLabel->setText("\t\t\t   Connecting to server..");

    }else {
         ui->loadingLabel->setText("\t\t\t   Connecting to server...");
    }
    loadLabelNumber ++;
    loadLabelNumber = loadLabelNumber % 4;

}


void gWindow::on_pushButton_clicked()
{
    mainwindow->show();  // Show a second window
 //   mainwindow->startGraph();
    this->close();    // Close the main window
}



#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
#include <mythread.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	// initilize the thread.
	myThread = new MyThread(); // this = when main window distory the thread automatically distroy.

	// connect thread to mainwindow.
	connect(myThread, SIGNAL(sendSignal(int)), this, SLOT(onSignalChange(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_start_thread1_clicked()
{

	// start button
	qDebug() << "Thread1 started";
	myThread->stop = false;

	myThread->start();
}

void MainWindow::on_btn_stop_thread1_clicked()
{

	// stop button.
	qDebug() << "Thread1 stoped\n";
	myThread->stop = true;
}

void MainWindow::onSignalChange(int number)
{

	if(number % 2 == 0) {
		// set number on line edit
		ui->le_thread1->setText(QString::number(number));
	}
}

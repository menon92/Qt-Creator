#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mythread.h>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

		// declare mythread.
		MyThread *myThread;

	private:
		Ui::MainWindow *ui;


	public slots:
		void onSignalChange(int);

	private slots:
		void on_btn_start_thread1_clicked();
		void on_btn_stop_thread1_clicked();
};

#endif // MAINWINDOW_H

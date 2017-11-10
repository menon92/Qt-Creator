#include "mythread.h"
#include <QDebug>
#include <QtCore>
#include <QMutex>

MyThread::MyThread()
{

}

void MyThread::run()
{
	for(int i = 0; i < 10000; i++)
	{
		QMutex qMutex;
		qMutex.lock();

		qDebug() << i;

		if(this->stop) {
			break;
		}
		qMutex.unlock();

		emit sendSignal(i);
		//this->sleep(1);  // spleep in second.
		this->msleep(100); // sleep in msecond.
	}
}

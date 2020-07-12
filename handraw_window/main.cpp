#include <iostream>
#include <Windows.h>
#include "mainwindow.h"
#include <QApplication>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <qurlquery.h>
#include <qfile.h>
#include <algorithm>
#include <functional>

void LogToFile(QtMsgType type, const QString &msg)
{
	QFile file("D:\\Qt Project\\tmp\\log.txt");
	if (!file.open(QIODevice::Append | QIODevice::Text)) {
		return;
	}
	QTextStream out(&file);

	QString curtime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ");
	//context.file, context.line, context.function
	switch (type) {
	case QtDebugMsg:
		out << "[Debug]" << curtime << msg << "\n";
		break;
	case QtInfoMsg:
		out << "[Info]" << curtime << msg << "\n";
		break;
	case QtWarningMsg:
		out << "[Warning]" << curtime << msg << "\n";
		break;
	}

	file.close();
}

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}
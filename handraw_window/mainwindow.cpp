#include "mainwindow.h"
#include "exit.h"
#include "handraw.h"
#include "Login.h"
#include "gameview.h"

#include <QVBoxLayout>
#include <QtWebEngineWidgets/qwebengineview.h>
#include <QWebEngineScript>
#include <QWebEngineView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	//this->setFixedSize(1280, 720);

    this->resize(1280, 720);

	setWindowModality(Qt::ApplicationModal);
	QPixmap bg("D:\\Qt Project\\Hackathon\\Handraw\\bg.png");
	bg = bg.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette p(palette());
	p.setBrush(QPalette::Background, bg);
	setAutoFillBackground(false);
	setPalette(p);

	//GameView *gameView = new GameView();
	//QIcon icon("moai.ico");
	//setWindowIcon(icon);
	setWindowFlags(Qt::FramelessWindowHint);
		
	QWidget *widget = new QWidget();
	QVBoxLayout *layout = new QVBoxLayout();

	Exit *exit = new Exit(this);
	Handraw *handraw = new Handraw(this);
	Login *login = new Login(this);
	//Webcam *webcam = new Webcam(this);

	//layout->addWidget(viewFinder);
	layout->addStretch(2);
	layout->addWidget(handraw);
	layout->addStretch(3);
	layout->addWidget(login);
	layout->addStretch(1);
	layout->addWidget(exit);

	widget->setLayout(layout);
	this->setCentralWidget(widget);	
}

MainWindow::~MainWindow()
{

}

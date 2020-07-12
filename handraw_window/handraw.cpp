#include "handraw.h"
#include <qlabel.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <qimage.h>
#include <qpixmap.h>

Handraw::Handraw(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout *vLayout = new QVBoxLayout();

	QLabel *label1 = new QLabel(QString::fromLocal8Bit("핸드로우"));
	QFont font1(QString::fromLocal8Bit("배달의민족 도현"), 32, QFont::Medium);
	QFont font2("Roboto", 24, QFont::Medium);

	font1.setBold(true);
	font2.setBold(true);

	label1->setFont(font1);
	label1->setAlignment(Qt::AlignCenter);
	label1->setStyleSheet("color: white");
	/*
	QLabel *logo = new QLabel();
	QImage image;
	image.load("moai.png");
	QPixmap buffer;
	buffer = QPixmap::fromImage(image);

	QPixmap myNewRessort = buffer.scaled(logo->size() * 0.2f, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	logo->setAlignment(Qt::AlignCenter);
	logo->setPixmap(myNewRessort);

	vLayout->setAlignment(Qt::AlignCenter);
	//vLayout->addWidget(label1);
	vLayout->addWidget(logo);
	*/
	vLayout->addWidget(label1);
	this->setLayout(vLayout);
}


Handraw::~Handraw()
{
}

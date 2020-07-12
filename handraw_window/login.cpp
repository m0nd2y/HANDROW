#include "login.h"
#include "D:/Qt Project/LIBRARY/Material/components/qtmaterialtextfield.h"
#include "D:/Qt Project/LIBRARY/Material/components/qtmaterialdialog.h"
#include "D:/Qt Project/LIBRARY/Material/components/qtmaterialtextfield.h"
#include "D:/Qt Project/LIBRARY/Material/components/qtmaterialflatbutton.h"
#include <QVBoxLayout>
#include <qlabel.h>
#include <qwebengineview.h>
#include <qurl.h>
#include <QThread>
#include <QtWebView>

#pragma comment(lib, "D:/Qt Project/LIBRARY/Material/components/release/components.lib")

Login::Login(QWidget *parent)
    : QWidget(parent),
      m_username(new QtMaterialTextField),
      m_password(new QtMaterialTextField),
	  m_loginDialog(new QtMaterialDialog)
{
    QVBoxLayout *layout = new QVBoxLayout();

	QtMaterialFlatButton *loginButton = new QtMaterialFlatButton("LOG IN");
	loginButton->setRole(Material::Role::Primary);
	loginButton->setMaximumWidth(150);
	loginButton->setMinimumWidth(150);

	QtMaterialFlatButton *loginDialogButton = new QtMaterialFlatButton("Log in");
	loginDialogButton->setRole(Material::Role::Primary);
	loginDialogButton->setMaximumWidth(150);
	loginDialogButton->setMinimumWidth(150);

	QtMaterialFlatButton *closeButton = new QtMaterialFlatButton("Close");
	closeButton->setRole(Material::Role::Secondary);
	closeButton->setMaximumWidth(150);
	closeButton->setMinimumWidth(150);

	QHBoxLayout *completeLayout = new QHBoxLayout();
	completeLayout->addWidget(loginDialogButton);
	completeLayout->addWidget(closeButton);

	QFont font(QString::fromLocal8Bit("Roboto"), 18, QFont::Medium);
	font.setBold(true);

	QLabel *loginTitle = new QLabel("LOG IN");
	loginTitle->setFont(font);
	loginTitle->setAlignment(Qt::AlignHCenter);

	QWidget *dialogWidget = new QWidget;
	QVBoxLayout *dialogWidgetLayout = new QVBoxLayout;

	dialogWidget->setLayout(dialogWidgetLayout);

	dialogWidgetLayout->addStretch(1);
	dialogWidgetLayout->addWidget(loginTitle);
	dialogWidgetLayout->addStretch(1);
	dialogWidgetLayout->addWidget(m_username);
	dialogWidgetLayout->setAlignment(m_username, Qt::AlignCenter);
	dialogWidgetLayout->addStretch(0);
	dialogWidgetLayout->addWidget(m_password);
	dialogWidgetLayout->setAlignment(m_password, Qt::AlignCenter);
	dialogWidgetLayout->addStretch(2);
	//dialogWidgetLayout->addWidget(closeButton);
	dialogWidgetLayout->addLayout(completeLayout);

	dialogWidgetLayout->setAlignment(closeButton, Qt::AlignBottom | Qt::AlignCenter);

	QVBoxLayout *dialogLayout = new QVBoxLayout;
	
	m_loginDialog->setWindowLayout(dialogLayout);
	dialogWidget->setMinimumHeight(300);
	dialogLayout->addWidget(dialogWidget);
	m_loginDialog->setParent(parent);
	layout->addWidget(loginButton);
	layout->setAlignment(loginButton, Qt::AlignCenter);

	connect(loginButton, SIGNAL(pressed()), m_loginDialog, SLOT(showDialog()));
	connect(closeButton, SIGNAL(pressed()), m_loginDialog, SLOT(hideDialog()));
    connect(loginDialogButton, &QtMaterialFlatButton::pressed, parent, [=]() {
        QWebEngineView *view = new QWebEngineView(parent);
        //view.setParent(parent);
        view->setUrl(QUrl("http://dimi.c2w2m2.com/"));
        parent->setFixedSize(1920, 1080);
        view->setFixedSize(1920, 1080);
        view->show();
        parent->move(0, 0);
    });

	this->setLayout(layout);

    m_username->setLabel("Username");
    m_username->setMinimumWidth(250);
    m_username->setMaximumWidth(250);
    m_username->setMaxLength(20);

    m_password->setLabel("Password");
    m_password->setMinimumWidth(250);
    m_password->setMaximumWidth(250);
    m_password->setMaxLength(20);
}
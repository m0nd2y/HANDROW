#include "gameview.h"
#include <QtWebView>
#include <qwebengineview.h>
#include <qurl.h>
#include <QVBoxLayout>

GameView::GameView(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout();
    this->setLayout(layout);

	QWebEngineView view;
    //view.setParent(parent);
	view.setUrl(QUrl("https://www.naver.com"));
	view.resize(1024, 750);
	view.show();
}


GameView::~GameView()
{
}

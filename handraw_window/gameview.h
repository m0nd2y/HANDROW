#pragma once
#include <qwidget.h>
#include <QtWebView>

class GameView : public QWidget
{
public:
	GameView(QWidget *parent = nullptr);
	~GameView();
};
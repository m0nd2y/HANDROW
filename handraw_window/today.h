#ifndef TODAY_H
#define TODAY_H

#include <QtNetwork>
#include <QWidget>

class Today : public QWidget
{
    Q_OBJECT
public:
    Today();
    QString getData(QString j);
	void postData(QString j);
private:
    QNetworkAccessManager *manager;
    QEventLoop connection_loop;
};

void LogToFile(QtMsgType type, const QString &msg);

#endif // TODAY_H
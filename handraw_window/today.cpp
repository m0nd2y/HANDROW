#include "today.h"

Today::Today()
{
    manager = new QNetworkAccessManager(this);
}

QString Today::getData(QString j)
{
    QNetworkRequest request;

    connect(manager, SIGNAL(finished(QNetworkReply*)), &connection_loop, SLOT(quit()));
    request.setUrl(QUrl("http://moai.dimigo.kr:8000"));
    //request.setUrl(QUrl("file:///C:/test.html"));
    QNetworkReply *reply = manager->get(request);
    connection_loop.exec();

    QByteArray data = reply->readAll();;

    //data.push_front('[');
    //data.push_back(']');

    QJsonDocument json_doc = QJsonDocument::fromJson(data);
    QString val;

    /*
    foreach (QJsonValue var, json_doc.array())
    {
        val = var.toObject().value(j).toString();
        qDebug()<<val;
    }
    */
    QJsonValue var = json_doc.array().first();

    val = var.toObject().value(j).toString();
    //qDebug()<<val;
	LogToFile(QtMsgType::QtDebugMsg, val);
	//LogToFile(QtMsgType::QtDebugMsg, QByteArray("http://hana.kimjisub.kr:3000/image/" + val.toStdWString()));
    return val;
}

void Today::postData(QString j)
{
	QUrl serviceUrl = QUrl("http://moai.dimigo.kr:8000");
	QByteArray postData;

	QUrl params;
	QUrlQuery query;
	query.addQueryItem("join", "string1");
	query.addQueryItem("join", "string2");

	params.setQuery(query);

	postData = params.toEncoded(QUrl::RemoveFragment);

	// Call the webservice
	QNetworkAccessManager *networkManager = new QNetworkAccessManager(this);
	connect(networkManager, SIGNAL(finished(QNetworkReply*)),
		SLOT(onPostAnswer(QNetworkReply*)));

	QNetworkRequest networkRequest(serviceUrl);
	networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

	networkManager->post(networkRequest, postData);
}

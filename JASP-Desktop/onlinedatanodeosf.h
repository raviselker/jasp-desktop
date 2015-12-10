#ifndef ONLINEDATANODEOSF_H
#define ONLINEDATANODEOSF_H

#include "onlinedatanode.h"
#include "common.h"

class OnlineDataNodeOSF: public OnlineDataNode
{
	Q_OBJECT

public:
	OnlineDataNodeOSF(QString localPath, QNetworkAccessManager *manager, QString id, QObject *parent = 0);

	virtual void initialise() OVERRIDE;

	virtual QString getUploadPath() const OVERRIDE;
	virtual QString getUploadPath(QString filename) const OVERRIDE;
	virtual QString getDownloadPath() const OVERRIDE;
	virtual QString getNewFolderPath(QString folderName) const OVERRIDE;
	virtual QString getDeletePath() const OVERRIDE;

	virtual void beginDownloadFile() OVERRIDE;
	virtual void beginUploadFile() OVERRIDE;
	virtual void beginUploadFile(QString name) OVERRIDE;
	virtual void beginNewFolder(QString name) OVERRIDE;

private slots:
	void nodeInfoReceived();
	//void checkFinished();

private:

	bool searchList(QString searchName, OnlineDataNode::Kind kind, QJsonArray arrayObject, QJsonObject &nodeObject);
	bool interpretNode(QJsonObject nodeObject);
	void extractNodeData(OnlineDataNodeOSF * node);
	OnlineDataNode::Kind parseKind(QString kind);
	void processUrl(QUrl url);
	QString getContentsUrl(QJsonObject nodeObject);
	void populateNodeData(QJsonObject nodeObject);
	QString getBaseUrl(QJsonObject nodeObject);

	QStringList _subPath;

	QString _contentsPath;

	OnlineDataNode::Kind _dataKind = OnlineDataNode::Unknown;
	QString _expectedName = "";

};

#endif // ONLINEDATANODEOSF_H

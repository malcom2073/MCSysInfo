#include "sysinfoprovider.h"
#include <QTimer>
#include <QSysInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

SysInfoProvider::SysInfoProvider(QObject *parent) : QObject(parent)
{
	m_ipc = new MCIPC("SysInfoProvider",this);
	m_ipc->connectToHost("127.0.0.1",12345);
	QTimer *timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(timerTick()));
	timer->start(100);
}
void SysInfoProvider::timerTick()
{
	QJsonObject sysinfoobj;
	sysinfoobj.insert("buildabi",QSysInfo::buildAbi());
	sysinfoobj.insert("buildCpuArch",QSysInfo::buildCpuArchitecture());
	sysinfoobj.insert("currentCpuArch",QSysInfo::currentCpuArchitecture());
	sysinfoobj.insert("kernelType",QSysInfo::kernelType());
	sysinfoobj.insert("kernelVersion",QSysInfo::kernelVersion());
	sysinfoobj.insert("machineHostName",QSysInfo::machineHostName());
	sysinfoobj.insert("prettyProductName",QSysInfo::prettyProductName());
	sysinfoobj.insert("productType",QSysInfo::productType());
	sysinfoobj.insert("productVersion",QSysInfo::productVersion());
	QByteArray message = QJsonDocument(sysinfoobj).toJson();
	m_ipc->publishMessage("SysInfoProvider/sysinfo",message);
}

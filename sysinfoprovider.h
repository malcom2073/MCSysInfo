#ifndef SYSINFOPROVIDER_H
#define SYSINFOPROVIDER_H

#include <QObject>
#include "mcipc.h"

class SysInfoProvider : public QObject
{
	Q_OBJECT
public:
	explicit SysInfoProvider(QObject *parent = 0);
private:
	MCIPC *m_ipc;
signals:

private slots:
	void timerTick();
public slots:
};

#endif // SYSINFOPROVIDER_H

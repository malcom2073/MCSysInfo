#include <QCoreApplication>
#include "sysinfoprovider.h"
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	SysInfoProvider sysinfo;
	return a.exec();
}

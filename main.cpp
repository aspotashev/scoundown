#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MainWindow mw(3);
	mw.showFullScreen();

	return app.exec();
}


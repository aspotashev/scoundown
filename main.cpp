#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	int opt;
	int nsecs = 300;
	while ((opt = getopt(argc, argv, "t:")) != -1)
	{
		switch (opt)
		{
		case 't':
			nsecs = atoi(optarg);
			break;
		default:
			fprintf(stderr, "Usage: guess!\n");
			exit(1);
		}
	}

	MainWindow mw(nsecs);
	mw.showFullScreen();

	return app.exec();
}


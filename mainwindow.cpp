#include <QTimer>
#include "mainwindow.h"

MainWindow::MainWindow()
{
	labelTime = new QLabel(this);
	setCentralWidget(labelTime);
	labelTime->show();

	timeLeft = 300; // 5 minutes

	labelTime->setFont(QFont("Monaco", 200, QFont::Bold));
	labelTime->setAlignment(Qt::AlignCenter);
	labelTime->setText("hello");

	QPalette pal = labelTime->palette();
	pal.setColor(QPalette::Window, QColor(0, 0, 0));
	pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
	labelTime->setPalette(pal);
	labelTime->setAutoFillBackground(true);

	timerTick = new QTimer(this);
	connect(timerTick, SIGNAL(timeout()), this, SLOT(tick()));
	timerTick->start(1000);
	tick();
}

MainWindow::~MainWindow()
{
}

void MainWindow::tick()
{
	labelTime->setText(QString("%1:%2")
		.arg(timeLeft / 60)
		.arg(timeLeft % 60, 2, 10, QChar('0')));
	
	if (timeLeft == 0)
	{
		labelTime->setText("XPEH");
		timerTick->stop();
	}

	timeLeft --;
}


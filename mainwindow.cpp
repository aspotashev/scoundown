#include <QTimer>
#include <QKeyEvent>
#include "mainwindow.h"

MainWindow::MainWindow(int timeOut)
{
	labelTime = new QLabel(this);
	setCentralWidget(labelTime);
	labelTime->show();

	timeLeft = timeOut;

	labelTime->setFont(QFont("Monaco", 200, QFont::Bold));
	labelTime->setAlignment(Qt::AlignCenter);
	labelTime->setText("hello");

	QPalette pal = labelTime->palette();
	pal.setColor(QPalette::Window, QColor(0, 0, 0));
	labelTime->setPalette(pal);
	labelTime->setAutoFillBackground(true);

	setTextColor(QColor(100, 100, 100));
	setTimeLabel();

	timerTick = new QTimer(this);
	connect(timerTick, SIGNAL(timeout()), this, SLOT(tick()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::setTextColor(const QColor &c)
{
	QPalette pal = labelTime->palette();
	pal.setColor(QPalette::WindowText, c);
	labelTime->setPalette(pal);
}

void MainWindow::startTimer()
{
	if (!timerTick->isActive())
	{
		setTextColor(QColor(255, 255, 255));
		timerTick->start(1000);
		tick();
	}
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_Space: startTimer(); break;
	case Qt::Key_Q: exit(0); break;
	case Qt::Key_M: setWindowState(windowState() ^ Qt::WindowFullScreen); break;
	default: break;
	}
}

void MainWindow::setTimeLabel()
{
	labelTime->setText(QString("%1:%2")
		.arg(timeLeft / 60)
		.arg(timeLeft % 60, 2, 10, QChar('0')));
}

void MainWindow::tick()
{
	setTimeLabel();

	if (timeLeft == 0)
	{
//		labelTime->setText("end");
		timerTick->stop();
	}

	timeLeft --;
}


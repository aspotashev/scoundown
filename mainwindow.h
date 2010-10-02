#include <QMainWindow>
#include <QLabel>
#include <QObject>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(int timeOut);
	~MainWindow();

	void startTimer();
	void setTimeLabel();
	void setTextColor(const QColor &c);

	void keyPressEvent(QKeyEvent *event);

	void paintEvent(QPaintEvent *event);

private slots:
	void tick();

private:
	QLabel *labelTime;
	QTimer *timerTick;

	int timeLeft;
};


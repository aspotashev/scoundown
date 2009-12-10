#include <QMainWindow>
#include <QLabel>
#include <QObject>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
	~MainWindow();

private slots:
	void tick();

private:
	QLabel *labelTime;
	QTimer *timerTick;

	int timeLeft;
};


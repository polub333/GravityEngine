#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

#include "engine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  //  void start();
private:
    Ui::MainWindow *ui;
    Engine* engine;
    QTimer* timer;
    QWidget* settings;
    int counter;

    qreal fps;
    qreal boost;
    qreal realInterval;

    void changeSettings(qreal, qreal, qreal);

private slots:
    void update();
    void on_SettingButton_clicked();
};
#endif // MAINWINDOW_H

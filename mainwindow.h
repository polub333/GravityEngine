#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMouseEvent>
#include "guiheaders.h"

#include "engine.h"
#include "createbodywindow.h"
#include "editbodywindow.h"
#include "settingswindow.h"
#include "bodylistwindow.h"
#include "statisticswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Engine* engine;
    QTimer* timer;
    Settings settings;
    Body* selectedBody;

    BodyWindow* createBodyWindow;
    BodyWindow* editBodyWindow;
    BodyListWindow* bodyListWindow;
    SettingsWindow* settingsWindow;
    StatisticsWindow* statisticsWindow;
    int counter;

    qreal realInterval;

    bool active;

    void showSelectedBodyInfo();
private slots:
    void update();
    void changeSettings(Settings);
    void setSelectedBody(Body*);
    void on_SettingsButton_clicked();
    void on_NewBodyButton_clicked();
    void on_StartPauseButton_clicked();
    void on_BodyListButton_clicked();
    void on_EditButton_clicked();
    void on_ForceFieldButton_clicked();

    void mouseMoveEvent(QMouseEvent*);
    void on_StatisticsButton_clicked();
};
#endif // MAINWINDOW_H

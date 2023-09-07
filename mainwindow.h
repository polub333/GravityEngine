#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>
#include <QMouseEvent>
#include "guiheaders.h"

#include "engine.h"
#include "createbodywindow.h"
#include "editbodywindow.h"
#include "settingswindow.h"
#include "bodylistwindow.h"
#include "statisticswindow.h"
#include "exportsystemwindow.h"
#include "importsystemwindow.h"

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

    Scene* scene;

    BodyWindow* createBodyWindow;
    BodyWindow* editBodyWindow;
    BodyListWindow* bodyListWindow;
    SettingsWindow* settingsWindow;
    StatisticsWindow* statisticsWindow;
    ExportSystemWindow* exportSystemWindow;
    ImportSystemWindow* importSystemWindow;

    int counter;

    qreal realInterval;

    bool active;

    void showSelectedBodyInfo();
private slots:
    void update();
    void changeSettings(Settings);
    void setSelectedBody(Body*);
    void exportSystem(QString);
    void importSystem(QString);

    void on_SettingsButton_clicked();
    void on_NewBodyButton_clicked();
    void on_StartPauseButton_clicked();
    void on_BodyListButton_clicked();
    void on_EditButton_clicked();
    void on_ForceFieldButton_clicked();

    void mouseMoveEvent(QMouseEvent*);
    void on_StatisticsButton_clicked();
    //void on_pushButton_clicked();
    void on_SaveSystemButton_clicked();
    void on_ImportSystemButton_clicked();
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , engine(new Engine)
    , createBodyWindow(new CreateBodyWindow(engine))
    , editBodyWindow(new EditBodyWindow)
    , bodyListWindow(new BodyListWindow(engine))
    , settingsWindow(new SettingsWindow)
    , statisticsWindow(new StatisticsWindow)
    , exportSystemWindow(new ExportSystemWindow)
    , importSystemWindow(new ImportSystemWindow)
{
    ui->setupUi(this);
    Scene* scene = new Scene();
    ui->SceneView->setScene(scene);

    realInterval = 1;

    ui->SceneView->setMouseTracking(true);


    scene->setSceneSize(ui->SceneView->width(), ui->SceneView->height());

    settings.setResolution(1000);
    settings.setTimeBoost(1);
    settings.setFps(100);

    engine->setScene(scene);
    engine->setSettings(settings);

    engine->importBodySystem("./Systems/system.txt");
    //engine->addBody(0, 0, 0, 0, 100, "NONE");
    //engine->addBody(50, 0, 0, 1, 0, "NONE");
    //engine->exportBodySystem();
    /*

    0 0 0 0 100000
    50 0 0 45 0

    */

    timer = new QTimer();
    counter = 0;

    selectedBody = nullptr;

    connect(settingsWindow, SIGNAL(sendSettings(Settings)), this, SLOT(changeSettings(Settings)));
    connect(engine, SIGNAL(setSelectedBody(Body*)), this, SLOT(setSelectedBody(Body*)));
    connect(exportSystemWindow, SIGNAL(exportSystem(QString)), this, SLOT(exportSystem(QString)));
    connect(importSystemWindow, SIGNAL(importSystem(QString)), this, SLOT(importSystem(QString)));

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->setInterval(realInterval);
    timer->start();
    active = true;
    ui->StartPauseButton->setText("Pause");

}

MainWindow::~MainWindow()
{
    qDebug()<<counter;
    delete createBodyWindow;
    delete editBodyWindow;
    delete bodyListWindow;
    delete settingsWindow;
    delete statisticsWindow;
    delete exportSystemWindow;
    delete importSystemWindow;
    delete ui;
}

void MainWindow::changeSettings(Settings _settings)
{
    settings = _settings;
    engine->setSettings(_settings);
}

void MainWindow::update()
{
    ++counter;
    if(counter%(int((1000/realInterval)/settings.getFps())) == 0){
        engine->drawAllBodies();
        showSelectedBodyInfo();
    }
    engine->changeAllBodies();
}

void MainWindow::on_SettingsButton_clicked()
{
    settingsWindow->open(settings);
}

void MainWindow::on_NewBodyButton_clicked()
{
    createBodyWindow->setBody();
}


void MainWindow::on_StartPauseButton_clicked()
{
    engine->setForceField(false);
    if(active){
        timer->stop();
        ui->StartPauseButton->setText("Start");
        active = false;
    }
    else{
        timer->start();
        ui->StartPauseButton->setText("Pause");
        active = true;
    }
}


void MainWindow::on_BodyListButton_clicked()
{
    bodyListWindow->open();
}

void MainWindow::setSelectedBody(Body* _selectedBody)
{
    selectedBody = _selectedBody;
}

void MainWindow::showSelectedBodyInfo()
{
    QString xCoord, yCoord, xVel, yVel;
    if(selectedBody == nullptr){
        xCoord = "";
        yCoord = "";
        xVel = "";
        yVel = "";
    }
    else{
        xCoord = QString::number(selectedBody->getCoordinates().first);
        yCoord = QString::number(selectedBody->getCoordinates().second);
        xVel = QString::number(selectedBody->getVelocity().first);
        yVel = QString::number(selectedBody->getVelocity().second);
    }
    ui->XCoordLabel->setText(xCoord);
    ui->YCoordLabel->setText(yCoord);
    ui->XVelLabel->setText(xVel);
    ui->YVelLabel->setText(yVel);
}

void MainWindow::on_EditButton_clicked()
{
    if(selectedBody == nullptr){
        return;
    }
    editBodyWindow->editBody(selectedBody);
}


void MainWindow::on_ForceFieldButton_clicked()
{
    if(engine->getForceField()){
        engine->setForceField(false);
        ui->ForceFieldButton->setText("Show Force Field");
    }
    else{
        engine->setForceField(true);
        ui->ForceFieldButton->setText("Hide Force Field");
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    //qDebug()<<event->pos();
}

void MainWindow::on_StatisticsButton_clicked()
{
    if(selectedBody != nullptr){
        statisticsWindow->open(selectedBody);
    }
}

void MainWindow::on_SaveSystemButton_clicked()
{
    exportSystemWindow->show();
}

void MainWindow::exportSystem(QString name)
{
    engine->exportBodySystem("./Systems/" + name + ".txt");
}

/*
void MainWindow::on_pushButton_clicked()
{

}ddd
*/

void MainWindow::on_ImportSystemButton_clicked()
{
    importSystemWindow->show();
}

void MainWindow::importSystem(QString name)
{
    engine->importBodySystem("./Systems/" + name + ".txt");
}


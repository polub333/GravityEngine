#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , engine(new Engine)
    , settings(new QWidget)
{
    ui->setupUi(this);
    Scene* scene = new Scene();
    ui->SceneView->setScene(scene);
    realInterval = 0.01;
    boost = 1;
    fps = 100;
    engine->setScene(scene);
    engine->setInter(realInterval * boost);
    engine->addBody(0, 0, 0, 0, 100000);
    engine->addBody(100, 0, 0, 15, 0);
    timer = new QTimer();
    counter = 0;

    QVBoxLayout* layout = new QVBoxLayout();

    QHBoxLayout* rIL = new QHBoxLayout();
    QLabel* rILb = new QLabel("Real Interval");
    QLineEdit* rILE = new QLineEdit();
    rILE->setText(QString::number(realInterval));
    rIL->addWidget(rILb);
    rIL->addWidget(rILE);

    QHBoxLayout* bL = new QHBoxLayout();
    QLabel* bLb = new QLabel("Time Boost");
    QLineEdit* bLE = new QLineEdit();
    bLE->setText(QString::number(boost));
    bL->addWidget(bLb);
    bL->addWidget(bLE);

    QHBoxLayout* fL = new QHBoxLayout();
    QLabel* fLb = new QLabel("FPS");
    QLineEdit* fLE = new QLineEdit();
    fLE->setText(QString::number(fps));
    fL->addWidget(fLb);
    fL->addWidget(fLE);

    QHBoxLayout* btnL = new QHBoxLayout();
    QPushButton* SubmitButton = new QPushButton();
    QPushButton* CancelButton = new QPushButton();
    SubmitButton->setText("Submit");
    CancelButton->setText("Cancel");
    btnL->addWidget(SubmitButton);
    btnL->addWidget(CancelButton);

    layout->addLayout(rIL);
    layout->addLayout(bL);
    layout->addLayout(fL);
    layout->addLayout(btnL);
    settings->setLayout(layout);

    connect(SubmitButton, &QPushButton::clicked, this, [=](){
        qreal rI = rILE->text().toDouble();
        qreal b = bLE->text().toDouble();
        qreal f = fLE->text().toDouble();
        this->changeSettings(rI, b, f);
    });
    connect(CancelButton, &QPushButton::clicked, this, [=](){
        rILE->setText(QString::number(realInterval));
        bLE->setText(QString::number(boost));
        fLE->setText(QString::number(fps));
    });


   // settings->setLayout(layout);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->setInterval(realInterval);
    timer->start();

}

MainWindow::~MainWindow()
{
    qDebug()<<counter;
    delete ui;
}

void MainWindow::update()
{
    ++counter;
    if(counter%(int((1000/realInterval)/fps)) == 0){
        engine->drawAllBodies();
    }
    engine->changeAllBodies();
}

void MainWindow::on_SettingButton_clicked()
{
    settings->show();
}

void MainWindow::changeSettings(qreal _realInterval, qreal _boost, qreal _fps)
{
    realInterval = _realInterval;
    boost = _boost;
    fps = _fps;

    engine->setInter(realInterval * boost);
    timer->setInterval(realInterval);

}

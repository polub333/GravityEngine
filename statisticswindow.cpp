#include "statisticswindow.h"
#include "ui_statisticswindow.h"

StatisticsWindow::StatisticsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatisticsWindow)
{
    ui->setupUi(this);
}

StatisticsWindow::~StatisticsWindow()
{
    delete ui;
}

void StatisticsWindow::open(Body* body)
{
    ui->BodyNameLabel->setText(body->getName());
    ui->MaximalXLabel->setText(QString::number(body->getMaxX()));
    ui->MinimalXLabel->setText(QString::number(body->getMinX()));
    ui->MaximalYLabel->setText(QString::number(body->getMaxY()));
    ui->MinimalYLabel->setText(QString::number(body->getMinY()));
    ui->MaximalXVelLabel->setText(QString::number(body->getMaxVelX()));
    ui->MinimalXVelLabel->setText(QString::number(body->getMinVelX()));
    ui->MaximalYVelLabel->setText(QString::number(body->getMaxVelY()));
    ui->MinimalYVelLabel->setText(QString::number(body->getMinVelY()));
    ui->MaximalVelLabel->setText(QString::number(body->getMaxVel()));
    ui->MinimalVelLabel->setText(QString::number(body->getMinVel()));
    ui->LifetimeLabel->setText(QString::number(body->getLifetime()));
    show();
}

void StatisticsWindow::on_CloseButton_clicked()
{
    hide();
}


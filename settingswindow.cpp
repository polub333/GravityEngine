#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    ui->ResolutionLabel->setToolTip("How many times in 1 ms calculations occur");
    ui->TimeBoostLabel->setToolTip("How many times the time in the program runs faster than real time");
    ui->FPSLabel->setToolTip("How many times per second objects are drawn");
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::open(const Settings settings)
{
    ui->ResolutionLineEdit->setText(QString::number(settings.getResolution()));
    ui->TimeBoostLineEdit->setText(QString::number(settings.getTimeBoost()));
    ui->FpsLineEdit->setText(QString::number(settings.getFps()));
    show();
}

void SettingsWindow::on_SubmitButton_clicked()
{
    bool ok1, ok2, ok3;
    qreal resolution = ui->ResolutionLineEdit->text().toDouble(&ok1);
    qreal timeBoost = ui->TimeBoostLineEdit->text().toDouble(&ok2);
    qreal fps = ui->FpsLineEdit->text().toDouble(&ok3);
    if(ok1 && ok2 && ok3){
        Settings settings;
        settings.setResolution(resolution);
        settings.setTimeBoost(timeBoost);
        settings.setFps(fps);
        emit sendSettings(settings);
    }
    else{
        QMessageBox msg(QMessageBox::Icon::Critical, "Invalid Parametrs",
                    "Some of the entered parameters are invalid", QMessageBox::StandardButton::Ok);
        msg.exec();
    }
}


void SettingsWindow::on_CancelButton_clicked()
{
    hide();
}


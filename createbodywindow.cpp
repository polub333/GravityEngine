#include "createbodywindow.h"
#include "ui_bodywindow.h"

CreateBodyWindow::CreateBodyWindow(Engine* _engine):
    engine(_engine)
{

}

void CreateBodyWindow::setBody()
{
    show();
}

void CreateBodyWindow::on_SubmitButton_clicked()
{
    bool ok1, ok2, ok3, ok4, ok5, ok6;
    qreal xCoord = ui->xCoordLineEdit->text().toDouble(&ok1);
    qreal yCoord = ui->yCoordLineEdit->text().toDouble(&ok2);
    qreal xVel = ui->xVelLineEdit->text().toDouble(&ok3);
    qreal yVel = ui->yVelLineEdit->text().toDouble(&ok4);
    qreal massNum = ui->MassNumLineEdit->text().toDouble(&ok5);
    qreal massExp = ui->MassExpLineEdit->text().toDouble(&ok6);
    QString name = ui->NameLineEdit->text();
    if(name == ""){
        name = "NONE";
    }
    if(ok1 && ok2 && ok3 && ok4 && ok5 && ok6){
        qreal mass = massNum * pow(10, massExp);
        engine->addBody(xCoord, yCoord, xVel, yVel, mass, name);
        hide();
    }
    else{
        QMessageBox msg(QMessageBox::Icon::Critical, "Invalid Parametrs",
                    "Some of the entered parameters are invalid", QMessageBox::StandardButton::Ok);
        msg.exec();
    }
}

void CreateBodyWindow::on_CancelButton_clicked()
{
    hide();
}

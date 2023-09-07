#include "editbodywindow.h"
#include "ui_bodywindow.h"

EditBodyWindow::EditBodyWindow()
{

}

void EditBodyWindow::editBody(Body* _body)
{
    body = _body;
    ui->xCoordLineEdit->setText(QString::number(body->getCoordinates().first));
    ui->yCoordLineEdit->setText(QString::number(body->getCoordinates().second));
    ui->xVelLineEdit->setText(QString::number(body->getVelocity().first));
    ui->yVelLineEdit->setText(QString::number(body->getVelocity().second));

    qreal mass = body->getMass();
    qreal num, exp = 0;
    while(mass / pow(10, exp) > 10){
        ++exp;
    }
    num = mass / pow(10, exp);

    ui->MassNumLineEdit->setText(QString::number(num));
    ui->MassExpLineEdit->setText(QString::number(exp));
    ui->NameLineEdit->setText(body->getName());
    show();
}

void EditBodyWindow::on_SubmitButton_clicked()
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
        body->setCoordinates(xCoord, yCoord);
        body->setVelocity(xVel, yVel);
        body->setMass(mass);
        body->setName(name);
        hide();
    }
    else{
        QMessageBox msg(QMessageBox::Icon::Critical, "Invalid Parametrs",
                    "Some of the entered parameters are invalid", QMessageBox::StandardButton::Ok);
        msg.exec();
    }
}

void EditBodyWindow::on_CancelButton_clicked()
{
    hide();
}

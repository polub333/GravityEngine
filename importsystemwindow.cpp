#include "importsystemwindow.h"
#include "ui_importsystemwindow.h"

ImportSystemWindow::ImportSystemWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImportSystemWindow)
{
    ui->setupUi(this);
}

ImportSystemWindow::~ImportSystemWindow()
{
    delete ui;
}

void ImportSystemWindow::on_CancelButton_clicked()
{
    ui->SystemNameLineEdit->clear();
    hide();
}


void ImportSystemWindow::on_SubmitButton_clicked()
{
    QString name = ui->SystemNameLineEdit->text();
    emit importSystem(name);
    ui->SystemNameLineEdit->clear();
    hide();
}


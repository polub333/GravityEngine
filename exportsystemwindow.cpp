#include "exportsystemwindow.h"
#include "ui_exportsystemwindow.h"

ExportSystemWindow::ExportSystemWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExportSystemWindow)
{
    ui->setupUi(this);
}

ExportSystemWindow::~ExportSystemWindow()
{
    delete ui;
}

void ExportSystemWindow::on_CancelButton_clicked()
{
    ui->SystemNameLineEdit->clear();
    hide();
}


void ExportSystemWindow::on_SubmitButton_clicked()
{
    QString name = ui->SystemNameLineEdit->text();
    emit exportSystem(name);
    ui->SystemNameLineEdit->clear();
    hide();
}


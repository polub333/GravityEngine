#include "bodywindow.h"
#include "ui_bodywindow.h"

BodyWindow::BodyWindow(Engine* engine, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BodyWindow)
{
    ui->setupUi(this);
}

BodyWindow::BodyWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::BodyWindow)
{
    ui->setupUi(this);
}

BodyWindow::~BodyWindow()
{
    delete ui;
}

void BodyWindow::setBody()
{

}

void BodyWindow::editBody(Body*)
{
//std::ignore = ;
}

void BodyWindow::on_SubmitButton_clicked()
{

}


void BodyWindow::on_CancelButton_clicked()
{

}


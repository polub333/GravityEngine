#ifndef CREATEBODYWINDOW_H
#define CREATEBODYWINDOW_H

#include <QMessageBox>

#include "bodywindow.h"

class CreateBodyWindow: public BodyWindow
{
public:
    CreateBodyWindow(Engine*);
    void setBody();
private:
    Engine* engine;
private slots:
    void on_SubmitButton_clicked();
    void on_CancelButton_clicked();
};

#endif // CREATEBODYWINDOW_H

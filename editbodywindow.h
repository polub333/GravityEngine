#ifndef EDITBODYWINDOW_H
#define EDITBODYWINDOW_H

#include <QMessageBox>

#include "bodywindow.h"

class EditBodyWindow: public BodyWindow
{
public:
    EditBodyWindow();
    void editBody(Body*);
private:
    Body* body;
private slots:
    void on_SubmitButton_clicked();
    void on_CancelButton_clicked();
};

#endif // EDITBODYWINDOW_H

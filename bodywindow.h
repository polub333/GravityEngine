#ifndef BODYWINDOW_H
#define BODYWINDOW_H

#include <QWidget>

#include "engine.h"
#include "body.h"

namespace Ui {
class BodyWindow;
}

class BodyWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BodyWindow(Engine*, QWidget *parent = nullptr);
    explicit BodyWindow(QWidget* parent = nullptr);
    ~BodyWindow();

    virtual void setBody();
    virtual void editBody(Body*);

private slots:
    virtual void on_SubmitButton_clicked();

    virtual void on_CancelButton_clicked();

public:
    Ui::BodyWindow *ui;
};

#endif // BODYWINDOW_H

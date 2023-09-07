#ifndef BODYLISTWINDOW_H
#define BODYLISTWINDOW_H

#include <QWidget>
#include "guiheaders.h"

#include "body.h"
#include "engine.h"

namespace Ui {
class BodyListWindow;
}

class BodyListWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BodyListWindow(QWidget *parent = nullptr);
    BodyListWindow(Engine*, QWidget* parent = nullptr);
    ~BodyListWindow();

    void open();

private:
    Ui::BodyListWindow *ui;
    Engine* engine;

    std::vector<QHBoxLayout*> layouts;
    std::vector<QLabel*> names;
    std::vector<QPushButton*> selectButtons;
    std::vector<QPushButton*> deleteButtons;
    void clearLayout(QLayout*);
private slots:
    void changeSelected(int);
    void deleteBody(int);
};

#endif // BODYLISTWINDOW_H

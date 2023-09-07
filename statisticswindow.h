#ifndef STATISTICSWINDOW_H
#define STATISTICSWINDOW_H

#include <QWidget>

#include "body.h"

namespace Ui {
class StatisticsWindow;
}

class StatisticsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StatisticsWindow(QWidget *parent = nullptr);
    ~StatisticsWindow();

    void open(Body*);
private slots:
    void on_CloseButton_clicked();

private:
    Ui::StatisticsWindow *ui;
};

#endif // STATISTICSWINDOW_H

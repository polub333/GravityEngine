#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QMessageBox>

#include "settings.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();

    void open(const Settings);
private slots:
    void on_SubmitButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::SettingsWindow *ui;
signals:
    void sendSettings(Settings);
};

#endif // SETTINGSWINDOW_H

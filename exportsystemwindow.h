#ifndef EXPORTSYSTEMWINDOW_H
#define EXPORTSYSTEMWINDOW_H

#include <QWidget>

namespace Ui {
class ExportSystemWindow;
}

class ExportSystemWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ExportSystemWindow(QWidget *parent = nullptr);
    ~ExportSystemWindow();

private slots:
    void on_CancelButton_clicked();

    void on_SubmitButton_clicked();

private:
    Ui::ExportSystemWindow *ui;

signals:
    void exportSystem(QString);
};

#endif // EXPORTSYSTEMWINDOW_H

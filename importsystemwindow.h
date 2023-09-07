#ifndef IMPORTSYSTEMWINDOW_H
#define IMPORTSYSTEMWINDOW_H

#include <QWidget>

namespace Ui {
class ImportSystemWindow;
}

class ImportSystemWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ImportSystemWindow(QWidget *parent = nullptr);
    ~ImportSystemWindow();

private slots:
    void on_CancelButton_clicked();

    void on_SubmitButton_clicked();

private:
    Ui::ImportSystemWindow *ui;

signals:
    void importSystem(QString);
};

#endif // IMPORTSYSTEMWINDOW_H

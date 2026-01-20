#ifndef MENU_WINDOW_H
#define MENU_WINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

private slots:
    void on_Review_clicked();

    void on_Start_clicked();

private:
    Ui::MenuWindow *ui;
};

#endif // MENU_WINDOW_H

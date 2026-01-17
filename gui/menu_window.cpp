#include "menu_window.h"
#include "main_window.h"
#include "ui_menu_window.h"

MenuWindow::MenuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_Review_clicked()
{
    QString file_path = QFileDialog::getOpenFileName (
        this,
        tr("Выберите файл лога"),
        QString(),
        tr("Log files (*.log *.txt);;All files (*)")
    );

    if (!file_path.isEmpty()) {
        ui->FilePath->setText(file_path);
    }
}


void MenuWindow::on_Start_clicked()
{
    QString path = ui->FilePath->text();
    QFileInfo check_file(path);

    if (!check_file.exists()) {
        QMessageBox::warning(this, "Ошибка", "Файл не найден!");
        return;
    }

    QString suf = check_file.suffix().toLower();

    if (suf != "txt" && suf != "log") {
        QMessageBox::warning(this, "Ошибка", "Расширение файла не поддерживается!");
        return;
    }

    MainWindow *main = new MainWindow;
    main->setAttribute(Qt::WA_DeleteOnClose);

    main->show();
}


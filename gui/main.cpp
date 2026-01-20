#include <QApplication>
#include "menu_window.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setApplicationName("Log analyzer");
    MenuWindow window;
    window.setWindowTitle("Menu");
    window.show();
    return app.exec();
}

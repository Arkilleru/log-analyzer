#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>

#include "../core/common.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(const AnalysisResult& res, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    AnalysisResult result_;

    void UpdateGeneralStats();
    void IPTable(const std::unordered_map<std::string, int>& ip);
    void ErrorsTypeTable(const std::unordered_map<std::string, int>& types);
    void TimeDistributionTable(std::unordered_map<std::string, int>& time);
};

#endif // MAIN_WINDOW_H

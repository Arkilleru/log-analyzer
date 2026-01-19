#include "main_window.h"
#include "ui_main_window.h"

void MainWindow::TimeDistributionTable(std::unordered_map<std::string, int>& time) {
    ui->TimeDistributionTable->setRowCount(24);

    for(int i = 0; i < 24; ++i) {
        std::string hour = std::to_string(i) + ":00";
        int count = 0;

        if (time.find(hour) != time.end()) {
            count = time[hour];
        }

        ui->TimeDistributionTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(hour)));
        ui->TimeDistributionTable->setItem(i, 1, new QTableWidgetItem(QString::number(count)));
    }

}

void MainWindow::ErrorsTypeTable(const std::unordered_map<std::string, int>& types) {
    ui->ErrorsTypeTable->setRowCount(types.size());

    int row = 0;
    for(const auto& [type, count] : types) {
        ui->ErrorsTypeTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(type)));
        ui->ErrorsTypeTable->setItem(row, 1, new QTableWidgetItem(QString::number(count)));

        ++row;
    }

}


void MainWindow::IPTable(const std::unordered_map<std::string, int>& Ip) {
    QVector<QPair<QString, int>> data;

    for(const auto& [ip, count] : Ip) {
        data.append({QString::fromStdString(ip), count});

    }

    std::sort(data.begin(), data.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    ui->IPTable->setRowCount(std::min(10, static_cast<int> (data.size())));

    for(int i = 0; i < ui->IPTable->rowCount(); ++i) {
        ui->IPTable->setItem(i, 0, new QTableWidgetItem(data[i].first));
        ui->IPTable->setItem(i, 1, new QTableWidgetItem(QString::number(data[i].second)));
    }

}

void MainWindow::UpdateGeneralStats() {
    ui->total->setText(QString::number(result_.total_processed));
    ui->failed_parses->setText(QString::number(result_.failed_parses));
    ui->successful->setText(QString::number(result_.successful_requests));
    ui->errors->setText(QString::number(result_.error_requests));

    IPTable(result_.ip);

    ErrorsTypeTable(result_.error_counts);

    TimeDistributionTable(result_.time_distribution);
}

MainWindow::MainWindow(const AnalysisResult& res, QWidget *parent)
    : result_(res), QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    UpdateGeneralStats();
}

MainWindow::~MainWindow()
{
    delete ui;
}


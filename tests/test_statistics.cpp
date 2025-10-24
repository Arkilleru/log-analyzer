#include "tests.h"


TEST(StatisticsTest, NormalTest) {
    Statistics statistic;
    LogInformation error_entry;
    error_entry.status = 400;
    error_entry.time = "[20/Oct/2025:18:32:01 +0300]";
    error_entry.ip = "192.168.1.10";
    error_entry.parse_success = true;

    AnalysisResult data = statistic.Process(error_entry);
    EXPECT_EQ(data.ip[error_entry.ip], 1);
    EXPECT_EQ(data.time_distribution["18"], 1);
    EXPECT_EQ(data.error_counts["400"], 1);
    EXPECT_EQ(data.error_requests, 1);
    EXPECT_EQ(data.successful_requests, 0);
}


TEST(StatisticsTest, NoErrorTest) {
    Statistics statistic;
    LogInformation error_entry;
    error_entry.status = 200;
    error_entry.time = "[20/Oct/2025:18:32:01 +0300]";
    error_entry.ip = "192.168.1.10";
    error_entry.parse_success = true;

    AnalysisResult data = statistic.Process(error_entry);
    EXPECT_EQ(data.successful_requests, 1);
}

TEST(statisticsTest, ParseFailTest) {
    Statistics statistic;
    LogInformation error_entry;
    error_entry.status = 500;
    error_entry.time = "[3/Oct/2025:12:32:01 +0300]";
    error_entry.ip = "240";
    error_entry.parse_success = false;

    AnalysisResult data = statistic.Process(error_entry);
    EXPECT_EQ(data.failed_parses, 1);
}
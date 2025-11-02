#include "tests.h"

TEST(AnalyzerTest, StandardTest) {
    Analyzer analyzer;
    std::string path = "tests/test_data/normal_test.log";
    std::string report = analyzer.analyze(path);

    EXPECT_TRUE(report.find("Sucсessful - 5") != std::string::npos);
    EXPECT_TRUE(report.find("Failed Parsing - 8") != std::string::npos);
    EXPECT_TRUE(report.find("192.168.2.145 - 4") != std::string::npos);
    EXPECT_TRUE(report.find("20:00 - 2") != std::string::npos);
    EXPECT_TRUE(report.find("500 - 2") != std::string::npos);
    EXPECT_FALSE(report.find("402 - 1") != std::string::npos);
}

TEST(AnalyzerTest, EmptyTest) {
    Analyzer analyzer;
    std::string path = "tests/test_data/empty_test.log";
    std::string report = analyzer.analyze(path);

    EXPECT_TRUE(report == "invalid file format or file empty");
}
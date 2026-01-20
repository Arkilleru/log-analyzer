#include "tests.h"

TEST(AnalyzerTest, StandardTest) {
    Analyzer analyzer;
    fs::path path = fs::path("test_data") / "normal_test.log";
    AnalysisResult res = analyzer.analyze(path.string());

    EXPECT_TRUE(res.successful_requests == 5);
    EXPECT_TRUE(res.failed_parses == 8);
    EXPECT_TRUE(res.ip["192.168.2.145"] == 4);
    EXPECT_TRUE(res.time_distribution["20:00"]  == 2);
    EXPECT_TRUE(res.error_counts["500"] == 2);
    EXPECT_FALSE(res.error_counts["402"] == 2);
}

TEST(AnalyzerTest, EmptyTest) {
    Analyzer analyzer;
    fs::path path = fs::path("test_data") / "empty_test.log";
    AnalysisResult res = analyzer.analyze(path.string());

    EXPECT_TRUE(res.total_processed == 0);
}
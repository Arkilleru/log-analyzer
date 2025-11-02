#include "tests.h"

class ReporterTest : public ::testing::Test {
protected:
    AnalysisResult createSampleData() {
        AnalysisResult result;
        
        result.total_processed = 1000;
        result.successful_requests = 850;
        result.error_requests = 150;
        result.failed_parses = 5;
        
        result.ip["192.168.1.100"] = 45;
        result.ip["10.0.0.25"] = 33;
        result.ip["203.0.113.45"] = 22;
        
        result.time_distribution["14:00"] = 15;
        result.time_distribution["15:00"] = 8;
        
        result.error_counts["404"] = 60;
        result.error_counts["500"] = 25;
        result.error_counts["403"] = 15;
        
        return result;
    }

    AnalysisResult createEmptyData() {
        AnalysisResult result;
        return result;
    }
};

TEST_F(ReporterTest, NormalTest) {
    AnalysisResult res = createSampleData();
    Reporter reporter;
    std::string report = reporter.GenerateTextReport(res);

    EXPECT_TRUE(report.find("Sucсessful - 850") != std::string::npos);
    EXPECT_TRUE(report.find("Failed Parsing - 5") != std::string::npos);
    EXPECT_TRUE(report.find("10.0.0.25 - 33") != std::string::npos);
    EXPECT_TRUE(report.find("14:00 - 15") != std::string::npos);
    EXPECT_TRUE(report.find("404 - 60") != std::string::npos);
    EXPECT_FALSE(report.find("303 - 3") != std::string::npos);

}

TEST_F(ReporterTest, EmptyTest) {
    AnalysisResult res = createEmptyData();
    Reporter reporter;
    std::string report = reporter.GenerateTextReport(res);

    EXPECT_TRUE(report == "invalid file format or file empty");
}

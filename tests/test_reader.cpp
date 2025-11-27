#include "tests.h"
#include <filesystem>
#include <fstream>


TEST(ReaderTest, SimpleTest) {
    Reader reader;
    fs::path test_path = fs::path("test_data") / "test_simple.txt";
    EXPECT_TRUE(reader.OpenFile(test_path.string()));
    EXPECT_TRUE(reader.MoreLines());
    reader.CloseFile();
}


TEST(ReaderTest, EmptyTest) {
    Reader reader;
    fs::path test_path = fs::path("test_data") / "test_empty.txt";

    std::cout << test_path << "\n";
    std::cout << fs::exists(test_path) << "\n";
    std::cout << fs::current_path() << "\n";

    EXPECT_TRUE(reader.OpenFile(test_path.string()));
    EXPECT_FALSE(reader.MoreLines());
    reader.CloseFile();
}

TEST(ReaderTest, SingleTest) {
    Reader reader;
    fs::path test_path = fs::path("test_data") / "test_single_line.txt";
    EXPECT_TRUE(reader.OpenFile(test_path.string()));
    EXPECT_TRUE(reader.MoreLines());
    reader.CloseFile();
}

TEST(ReaderTest, ImaginaryTest) {
    Reader reader;
    fs::path test_path = fs::path("test_data") / "Imaginary.txt";
    EXPECT_FALSE(reader.OpenFile(test_path.string()));
}
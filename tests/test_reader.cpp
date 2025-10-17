#include "tests.h"

TEST(ReaderTest, SimpleTest) {
    Reader reader;
    std::string testFile = "tests/test_data/test_simple.txt";
    EXPECT_TRUE(reader.OpenFile(testFile));
    EXPECT_TRUE(reader.MoreLines());
    reader.CloseFile();
}


TEST(ReaderTest, EmptyTest) {
    Reader reader;
    std::string testFile = "tests/test_data/test_empty.txt";
    EXPECT_TRUE(reader.OpenFile(testFile));
    EXPECT_FALSE(reader.MoreLines());
    reader.CloseFile();
}

TEST(ReaderTest, SingleTest) {
    Reader reader;
    std::string testFile = "tests/test_data/test_single_line.txt";
    EXPECT_TRUE(reader.OpenFile(testFile));
    EXPECT_TRUE(reader.MoreLines());
    reader.CloseFile();
}

TEST(ReaderTest, ImaginaryTest) {
    Reader reader;
    std::string testFile = "Imaginary.txt";
    EXPECT_FALSE(reader.OpenFile(testFile));
}
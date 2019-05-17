#include <gtest/gtest.h>
#include "functions.h"

TEST (algoritmFindPaddingTest, paddingExists) { 
    EXPECT_EQ (0, isCircle ("abab", "abab"));
    EXPECT_EQ (3, isCircle ("padding", "dingpad"));
}
 
TEST (algoritmFindPaddingTest, paddingDoesNotExist) { 
    ASSERT_EQ (-1, isCircle ("abcd", "abcde"));
    ASSERT_EQ (-1, isCircle ("abcde", "abcd"));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

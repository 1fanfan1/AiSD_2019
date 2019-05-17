#include <gtest/gtest.h>
#include "functions.h"

TEST (algoritmKmpTest, substringExists) { 
    EXPECT_EQ ("0,2,5,8", algoritmKmp ("ababkabbab", "ab"));
}
 
TEST (algoritmKmpTest, substringDoesNotExist) { 
    ASSERT_EQ ("-1", algoritmKmp ("abcd", "abcef"));
    ASSERT_EQ ("-1", algoritmKmp ("abcd", "ad"));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

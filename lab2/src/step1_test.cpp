#include <gtest/gtest.h>
#include "functions_step1.h"

TEST (algoritmAxoKarasikTest, substringExists1Pattern) {
    AxoKarasik axoKarasik;
    string text = "CCCA"; 
    axoKarasik.addPattern("CC");
    EXPECT_EQ ("1 1\n2 1\n", axoKarasik.searchString(text));
}

TEST (algoritmAxoKarasikTest, substringExists4Patterns) {
    AxoKarasik axoKarasik;
    string text = "NGATCG"; 
    axoKarasik.addPattern("AT");
    axoKarasik.addPattern("GAT");
    axoKarasik.addPattern("ATC");
    axoKarasik.addPattern("ATCG");
    EXPECT_EQ ("2 2\n3 1\n3 3\n3 4\n", axoKarasik.searchString(text));
}
 
TEST (algoritmAxoKarasikTest, substringDoesNotExist) { 
    AxoKarasik axoKarasik;
    string text = "CCCA"; 
    axoKarasik.addPattern("GA");
    ASSERT_EQ ("", axoKarasik.searchString(text));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

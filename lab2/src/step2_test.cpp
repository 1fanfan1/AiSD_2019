#include <gtest/gtest.h>
#include "functions_step2.h"

TEST (algoritmAxoKarasikWithJokerTest, with1Joker) {
 
    string text = "ACT";
    string pattern = "A*";
    char joker = '*';
    AxoKarasikWithJoker axoKarasik(pattern);
    string additionStr = "";

    for (int i = 0; i < pattern.size(); i++){
        if (pattern[i] != joker)
            additionStr = additionStr + pattern[i];
        else
            if (additionStr.size() != 0) {
                axoKarasik.addPattern(additionStr, i - additionStr.size());
                additionStr = "";
            }
    }
    if (additionStr.size() != 0)
        axoKarasik.addPattern(additionStr, pattern.size() - additionStr.size());

    EXPECT_EQ ("1\n", axoKarasik.searchString(text));
}
 
TEST (algoritmAxoKarasikWithJokerTest, with2Jokers) { 
    string text = "BANANAS";
    string pattern = "*AN*";
    char joker = '*';
    AxoKarasikWithJoker axoKarasik(pattern);
    string additionStr = "";

    for (int i = 0; i < pattern.size(); i++){
        if (pattern[i] != joker)
            additionStr = additionStr + pattern[i];
        else
            if (additionStr.size() != 0) {
                axoKarasik.addPattern(additionStr, i - additionStr.size());
                additionStr = "";
            }
    }
    if (additionStr.size() != 0)
        axoKarasik.addPattern(additionStr, pattern.size() - additionStr.size());

    EXPECT_EQ ("1\n3\n", axoKarasik.searchString(text));
}
 

TEST (algoritmAxoKarasikWithJokerTest, substringWasNotFound) { 
    string text = "BANANAS";
    string pattern = "*G";
    char joker = '*';
    AxoKarasikWithJoker axoKarasik(pattern);
    string additionStr = "";

    for (int i = 0; i < pattern.size(); i++){
        if (pattern[i] != joker)
            additionStr = additionStr + pattern[i];
        else
            if (additionStr.size() != 0) {
                axoKarasik.addPattern(additionStr, i - additionStr.size());
                additionStr = "";
            }
    }
    if (additionStr.size() != 0)
        axoKarasik.addPattern(additionStr, pattern.size() - additionStr.size());

    EXPECT_EQ ("", axoKarasik.searchString(text));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

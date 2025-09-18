#include <gtest/gtest.h>
#include "remove_vowels.h"

TEST(RemoveVowelsTest, BasicExamples) {
    EXPECT_EQ(remove_vowels("This website is for losers LOL!"),
              "Ths wbst s fr lsrs LL!");
    EXPECT_EQ(remove_vowels("AEIOUYaeiouy"), "");
    EXPECT_EQ(remove_vowels(""), "");
    EXPECT_EQ(remove_vowels("xyz"), "xz");
    EXPECT_EQ(remove_vowels("Programming"), "Prgrmmng");
}

TEST(RemoveVowelsTest, PunctuationAndSpaces) {
    EXPECT_EQ(remove_vowels("Hello, World!"), "Hll, Wrld!");
    EXPECT_EQ(remove_vowels("   spaces   "), "   spcs   ");
    EXPECT_EQ(remove_vowels("...!?,.;"), "...!?,.;");
    EXPECT_EQ(remove_vowels("a.e.i.o.u"), "....");
}

TEST(RemoveVowelsTest, NumbersAndSpecialChars) {
    EXPECT_EQ(remove_vowels("12345"), "12345");
    EXPECT_EQ(remove_vowels("h3ll0 w0rld"), "h3ll0 w0rld");
    EXPECT_EQ(remove_vowels("@#$%^&*()"), "@#$%^&*()");
    EXPECT_EQ(remove_vowels("mix3d_up_1nput"), "mx3d_p_1npt");
}

TEST(RemoveVowelsTest, CaseSensitivity) {
    EXPECT_EQ(remove_vowels("UPPER CASE"), "PPR CS");
    EXPECT_EQ(remove_vowels("lower case"), "lwr cs");
    EXPECT_EQ(remove_vowels("MixeD cAsE"), "MxD cs");
    EXPECT_EQ(remove_vowels("CamelCase"), "CmlCs");
}

TEST(RemoveVowelsTest, LongStrings) {
    EXPECT_EQ(remove_vowels("The quick brown fox jumps over the lazy dog"),
              "Th qck brwn fx jmps vr th lz dg");
    EXPECT_EQ(remove_vowels("Lorem ipsum dolor sit amet"),
              "Lrm psm dlr st mt");
}
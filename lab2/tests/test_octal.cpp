#include <gtest/gtest.h>
#include "Octal.h"

TEST(OctalTest, DefaultConstructor) {
    Octal num;
    EXPECT_EQ(num.toString(), "0");
}

TEST(OctalTest, StringConstructor) {
    Octal num("755");
    EXPECT_EQ(num.toString(), "755");
}

TEST(OctalTest, InitializerListConstructor) {
    Octal num({5, 5, 7});
    EXPECT_EQ(num.toString(), "755");
}

TEST(OctalTest, Addition) {
    Octal a("123");
    Octal b("456");
    Octal result = a.add(b);
    EXPECT_EQ(result.toString(), "601");
}

TEST(OctalTest, Subtraction) {
    Octal a("456");
    Octal b("123");
    Octal result = a.subtract(b);
    EXPECT_EQ(result.toString(), "333");
}

TEST(OctalTest, Comparison) {
    Octal a("123");
    Octal b("456");
    Octal c("123");
    
    EXPECT_TRUE(a.less(b));
    EXPECT_TRUE(b.greater(a));
    EXPECT_TRUE(a.equals(c));
}

TEST(OctalTest, InvalidDigit) {
    EXPECT_THROW(Octal("189"), std::invalid_argument);
}

TEST(OctalTest, NegativeSubtraction) {
    Octal a("123");
    Octal b("456");
    EXPECT_THROW(a.subtract(b), std::invalid_argument);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

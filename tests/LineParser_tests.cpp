#include "gtest/gtest.h"
#include "LineParser.h"

TEST(TestGroup1, Test1)
{
    ASSERT_EQ(0, 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}

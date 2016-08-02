#include "Tests/UnitTests.hpp"

#include "Tests/UnitTest_Lexer.hpp"

UnitTests::UnitTests(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
}

int UnitTests::run()
{
    return RUN_ALL_TESTS();
}

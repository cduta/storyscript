#include "Lexer.hpp"

#include <string>

#include "Tests/UnitTests.hpp"

bool testIfNeeded(int argc, char** args)
{
    if(argc > 1)
    {
        std::string argument = std::string(args[1]);

        return argument == "--test";
    }

    return false;
}

int main(int argc, char** args)
{
    if(testIfNeeded(argc, args))
    {
        UnitTests unitTests(argc, args);
        return unitTests.run();
    }
    else
    {
        // Whatever...
    }

    return 0;
}

#include "Lexer.hpp"

#include "Tokens/EndOfFileToken.hpp"
#include "Tokens/ErrorToken.hpp"
#include "UTF8Character.hpp"
#include "UTF8IStream.hpp"

Token *Lexer::getToken(std::istream &stream)
{
    Token *result = nullptr;
    UTF8IStream utf8Stream(stream);

    // Ignore comments and whitespace. (/* ... */, //, and anything defined through <cctype> via iscntrl or isspace.
    if(!utf8Stream.ignoreCommentsAndWhitespace())
    {
        return nullptr;
    }

    UTF8Character current = utf8Stream.getChar();

    if(current.isEndOfFile()) // End of File
    {
        result = new EndOfFileToken();
    }
    else
    {
        // [Alphabet][AlphaNumerical]*
           // Specific Syntax:
           // ...
        // [Numerical]+
    }

    if(result == nullptr)
    {
        result = new ErrorToken();
    }

    return result;
}

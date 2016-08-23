#include "Lexer.hpp"

#include "Tokens/IdentifierToken.hpp"
#include "Tokens/IntegerToken.hpp"
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
        std::string currentTokenString = "";

        // [Alphabet][AlphaNumerical]*
        if(current.isAlphabet())
        {
            while(current.isAlphaNumeric())
            {
                currentTokenString.append(current.toString());
                current = utf8Stream.getChar();
            }

            utf8Stream.ungetChar(current.getCharacterSize());

            result = new IdentifierToken(currentTokenString);
        }
        else if(current.isNumeric()) // [Numerical]+
        {
            while(current.isNumeric())
            {
                currentTokenString.append(current.toString());
                current = utf8Stream.getChar();
            }

            utf8Stream.ungetChar(current.getCharacterSize());

            result = new IntegerToken(currentTokenString);
        }
    }

    if(result == nullptr)
    {
        result = new ErrorToken("The given input was malformed.");
    }

    return result;
}

std::vector<Token *> Lexer::tokenize(std::istream &stream)
{
    std::vector<Token *> result;

    Token *current = nullptr;

    do {
        current = Lexer::getToken(stream);
        result.push_back(current);
    } while(current->getType() != Token::END_OF_FILE && current->getType() != Token::ERROR);

    if(current != nullptr && current->getType() == Token::ERROR)
    {
        // Error Output when tokenizer fails. (Malformed code)
    }

    return result;
}

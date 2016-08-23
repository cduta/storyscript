#include "Tokens/EndOfFileToken.hpp"

EndOfFileToken::EndOfFileToken()
    : Token("EOF")
{
}

Token::Type EndOfFileToken::getType() const
{
    return Token::Type::END_OF_FILE;
}

Token::Group EndOfFileToken::getGroup() const
{
    return Token::MISC_GROUP;
}

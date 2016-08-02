#include "Tokens/EndOfFileToken.hpp"

Token::Type EndOfFileToken::getType() const
{
    return Token::Type::END_OF_FILE;
}

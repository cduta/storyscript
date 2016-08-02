#include "Tokens/ErrorToken.hpp"

Token::Type ErrorToken::getType() const
{
    return Token::Type::ERROR;
}

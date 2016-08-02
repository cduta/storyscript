#include "Tokens/ErrorToken.hpp"

Token::Type ErrorToken::getType() const
{
    return Token::Type::ERROR;
}

Token::Group ErrorToken::getGroup() const
{
    return Token::MISC_GROUP;
}

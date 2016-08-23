#include "Tokens/ErrorToken.hpp"

ErrorToken::ErrorToken(const std::string errorDescriptionToken)
    : Token(errorDescriptionToken)
{
}

Token::Type ErrorToken::getType() const
{
    return Token::Type::ERROR;
}

Token::Group ErrorToken::getGroup() const
{
    return Token::MISC_GROUP;
}

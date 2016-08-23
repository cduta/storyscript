#include "Tokens/IntegerToken.hpp"

IntegerToken::IntegerToken(const std::string &integerString)
    : Token(integerString)
{
}

Token::Type IntegerToken::getType() const
{
    return Token::Type::INTEGER;
}

Token::Group IntegerToken::getGroup() const
{
    return Token::PRIMITIVE_GROUP;
}

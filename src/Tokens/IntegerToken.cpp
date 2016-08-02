#include "Tokens/IntegerToken.hpp"

Token::Type IntegerToken::getType() const
{
    return Token::Type::INTEGER;
}

Token::Group IntegerToken::getGroup() const
{
    return Token::PRIMITIVE_GROUP;
}

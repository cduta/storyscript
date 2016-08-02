#include "Tokens/IdentifierToken.hpp"

Token::Type IdentifierToken::getType() const
{
    return Token::Type::IDENTIFIER;
}

Token::Group IdentifierToken::getGroup() const
{
    return Token::SYNTAX_GROUP;
}

#include "Tokens/IdentifierToken.hpp"

IdentifierToken::IdentifierToken(const std::__cxx11::string &identifierString)
    : Token(identifierString)
{
}

Token::Type IdentifierToken::getType() const
{
    return Token::Type::IDENTIFIER;
}

Token::Group IdentifierToken::getGroup() const
{
    return Token::SYNTAX_GROUP;
}

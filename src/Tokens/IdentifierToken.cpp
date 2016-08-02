#include "Tokens/IdentifierToken.hpp"

Token::Type IdentifierToken::getType() const
{
    return Token::Type::IDENTIFIER;
}

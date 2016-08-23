#include "Tokens/Token.hpp"

Token::Token(const std::__cxx11::string &tokenString)
    : tokenString(tokenString)
{
}

std::string Token::getTokenString() const
{
    return this->tokenString;
}

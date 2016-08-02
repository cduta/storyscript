#ifndef __IDENTIFIER_TOKEN_HPP__
#define __IDENTIFIER_TOKEN_HPP__

#include "Token.hpp"

/**
 * @brief The IdentifierToken class
 */
class IdentifierToken : public Token
{
public:
    virtual Type getType() const;
    virtual Group getGroup() const;
};

#endif

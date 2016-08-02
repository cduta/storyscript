#ifndef __IDENTIFIER_TOKEN_HPP__
#define __IDENTIFIER_TOKEN_HPP__

#include "Token.hpp"
#include "SyntaxGroup.hpp"

/**
 * @brief The IdentifierToken class
 */
class IdentifierToken : public Token, public SyntaxGroup
{
public:
    virtual Type getType() const;
};

#endif

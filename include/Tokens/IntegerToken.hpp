#ifndef __INTEGER_TOKEN_HPP__
#define __INTEGER_TOKEN_HPP__

#include "Token.hpp"
#include "PrimitiveGroup.hpp"

/**
 * @brief The IntegerToken class
 */
class IntegerToken : public Token, public PrimitiveGroup
{
public:
    virtual Type getType() const;
};

#endif

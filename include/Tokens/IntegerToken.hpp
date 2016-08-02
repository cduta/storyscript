#ifndef __INTEGER_TOKEN_HPP__
#define __INTEGER_TOKEN_HPP__

#include "Token.hpp"

/**
 * @brief The IntegerToken class
 */
class IntegerToken : public Token
{
public:
    virtual Type getType() const;
    virtual Group getGroup() const;
};

#endif

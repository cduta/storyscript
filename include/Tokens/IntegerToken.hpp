#ifndef __INTEGER_TOKEN_HPP__
#define __INTEGER_TOKEN_HPP__

#include <string>

#include "Token.hpp"

/**
 * @brief The IntegerToken class
 */
class IntegerToken : public Token
{
public:
    IntegerToken(const std::string &integerString);

    virtual Type getType() const;
    virtual Group getGroup() const;
};

#endif

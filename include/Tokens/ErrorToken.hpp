#ifndef __ERROR_TOKEN_HPP__
#define __ERROR_TOKEN_HPP__

#include "Token.hpp"

/**
 * @brief The ErrorToken class
 */
class ErrorToken : public Token
{
public:
    virtual Type getType() const;
    virtual Group getGroup() const;
};

#endif

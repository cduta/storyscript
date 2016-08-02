#ifndef __ERROR_TOKEN_HPP__
#define __ERROR_TOKEN_HPP__

#include "Token.hpp"
#include "MiscGroup.hpp"

/**
 * @brief The ErrorToken class
 */
class ErrorToken : public Token, public MiscGroup
{
public:
    virtual Type getType() const;
};

#endif

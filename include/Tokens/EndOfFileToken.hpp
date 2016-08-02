#ifndef __END_OF_FILE_TOKEN_HPP__
#define __END_OF_FILE_TOKEN_HPP__

#include "Token.hpp"

/**
 * @brief The EndOfFileToken class
 */
class EndOfFileToken : public Token
{
public:
    virtual Type getType() const;
    virtual Group getGroup() const;
};

#endif

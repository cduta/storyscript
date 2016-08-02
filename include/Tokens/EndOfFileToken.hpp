#ifndef __END_OF_FILE_TOKEN_HPP__
#define __END_OF_FILE_TOKEN_HPP__

#include "Token.hpp"
#include "MiscGroup.hpp"

/**
 * @brief The EndOfFileToken class
 */
class EndOfFileToken : public Token, public MiscGroup
{
public:
    virtual Type getType() const;
};

#endif

#ifndef __TOKEN_HPP__
#define __TOKEN_HPP__

/**
 * @brief The Token class to represent a lexer token as a baseclass.
 */
class Token
{
public:
    /**
     * @brief The enum representing different token types.
     */
    enum Type
    {
        ERROR = 0,
        END_OF_FILE,
        DEFINITION,
        EXTERN,
        IDENTIFIER,
        INTEGER,
        TOKEN_TYPE_COUNT
    };

    virtual Type getType() const = 0;
};

#endif

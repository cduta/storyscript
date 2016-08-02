#ifndef __UTF8_ISTREAM_HPP__
#define __UTF8_ISTREAM_HPP__

#include <istream>

#include "UTF8Character.hpp"

class UTF8IStream
{
    std::istream &stream;

public:
    explicit UTF8IStream(std::istream &stream);

    /**
     * @brief ignoreCommentsAndWhitespace
     *        Whitespace is defined through the function of <cctype> as: iscntrl or isspace.
     *        Comments can either be // until the end of line or \/* until *\/ is found.
     * @return Returns false, in case something goes wrong and any of the possible comments or whitespaces are malformed.
     */
    bool ignoreCommentsAndWhitespace();

    UTF8Character getChar() const;
    void ungetChar(int characterSize);
};

#endif

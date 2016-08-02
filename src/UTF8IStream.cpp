#include "UTF8IStream.hpp"

#include <string>
#include <UTF8Character.hpp>

UTF8IStream::UTF8IStream(std::istream &stream)
    : stream(stream)
{}

bool UTF8IStream::ignoreCommentsAndWhitespace()
{
    UTF8Character currentCharacter = this->getChar();

    if(!currentCharacter.isValid())
    {
        return false;
    }

    while(currentCharacter != (char)(std::char_traits<char>::eof()) &&
          (currentCharacter.isControl() || currentCharacter.isSpace() || currentCharacter == '/'))
    {
        if(currentCharacter == '/') // May be comment or malformed.
        {
            UTF8Character next = this->getChar();

            if(next == '/')
            {
                while(next != '\n' && next != '\r' && next != (char)(std::char_traits<char>::eof()))
                {
                    next = this->getChar();
                }

                if(next == (char)(std::char_traits<char>::eof()))
                {
                    this->ungetChar(next.getCharacterSize());
                }
            }
            else if(next == '*')
            {
                bool done = false;
                while(!done)
                {
                    next = this->getChar();

                    if(next == '*')
                    {
                        next = this->getChar();

                        if(next == (char)(std::char_traits<char>::eof()))
                        {
                            return false;
                        }

                        if(next == '/')
                        {
                            done = true;
                        }
                    }
                }
            }
            else
            {
                return false;
            }
        }

        currentCharacter = this->getChar();
    }

    this->ungetChar(currentCharacter.getCharacterSize());

    return true;
}

/**
 * @brief UTF8IStream::getChar
 * @return Returns the next UTF8Character from the stream. The UTF8Character may be invalid, depending on what has been read.
 */
UTF8Character UTF8IStream::getChar() const
{
    UTF8Character result;
    char firstCharacter = this->stream.get();

    if(firstCharacter == std::char_traits<char>::eof())
    {
        return UTF8Character(true);
    }

    int characterSize = UTF8Character::characterSize(firstCharacter);

    if(characterSize <= 0)
    {
        return result;
    }

    switch(characterSize)
    {
        case 1:
        {
            result = UTF8Character(firstCharacter);
            break;
        }
        case 2:
        {
            char c2 = this->stream.get();

            if(c2 == std::char_traits<char>::eof())
            {
                return result;
            }

            result = UTF8Character(firstCharacter, c2);
            break;
        }
        case 3:
        {
            char c2 = this->stream.get();

            if(c2 == std::char_traits<char>::eof())
            {
                return result;
            }

            char c3 = this->stream.get();

            if(c3 == std::char_traits<char>::eof())
            {
                return result;
            }

            result = UTF8Character(firstCharacter, c2, c3);
            break;
        }
        case 4:
        {
            char c2 = this->stream.get();

            if(c2 == std::char_traits<char>::eof())
            {
                return result;
            }

            char c3 = this->stream.get();

            if(c3 == std::char_traits<char>::eof())
            {
                return result;
            }

            char c4 = this->stream.get();

            if(c4 == std::char_traits<char>::eof())
            {
                return result;
            }

            result = UTF8Character(firstCharacter, c2, c3, c4);
            break;
        }
        default: break;
    }

    return result;
}

/**
 * @brief UTF8IStream::ungetChar
 * @param Unget characters based on size.
 */
void UTF8IStream::ungetChar(int characterSize)
{
    for(int i = 0; i < characterSize; ++i)
    {
        this->stream.unget();
    }
}

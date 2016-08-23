#include "UTF8Character.hpp"

#include <cctype>

UTF8Character::UTF8Character(bool isEndOfFile)
{
    this->endOfFile = isEndOfFile;
}

UTF8Character::UTF8Character(char c1)
{
    this->endOfFile = false;
    this->utf8Character.append(1,c1);
}

UTF8Character::UTF8Character(char c1, char c2)
{
    this->endOfFile = false;
    this->utf8Character.append(1,c1);
    this->utf8Character.append(1,c2);
}

UTF8Character::UTF8Character(char c1, char c2, char c3)
{
    this->endOfFile = false;
    this->utf8Character.append(1,c1);
    this->utf8Character.append(1,c2);
    this->utf8Character.append(1,c3);
}

UTF8Character::UTF8Character(char c1, char c2, char c3, char c4)
{
    this->endOfFile = false;
    this->utf8Character.append(1,c1);
    this->utf8Character.append(1,c2);
    this->utf8Character.append(1,c3);
    this->utf8Character.append(1,c4);
}

/**
 * @brief UTF8Character::characterSize
 * @param c
 * @return Returns the character size based on the given c. Is -1, if c was not valid.
 */
int UTF8Character::characterSize(char c)
{
    int result = -1;

    if ((c & 0x80) == 0x00)
    {
        // \u0000 to \u007F
        result = 1;
    }
    else if ((c & 0xE0) == 0xC0)
    {
        // \u0080 to \u07FF
        result = 2;
    }
    else if ((c & 0xF0) == 0xE0)
    {
        // \u0800 to \uFFFF
        result = 3;
    }
    else if ((c & 0xF8) == 0xF0)
    {
        // \U10000 to \U10FFFF
        result = 4;
    }

    return result;
}

int UTF8Character::toInteger() const
{
    int result = 0;

    for(int i = 0; i < this->utf8Character.size(); ++i)
    {
        int current = (unsigned char)this->utf8Character.at(i);
        result = result | (current << 8*i);
    }

    return result;
}

std::string UTF8Character::toString() const
{
    return this->utf8Character;
}

int UTF8Character::getCharacterSize() const
{
    return this->utf8Character.size();
}

bool UTF8Character::isValid() const
{
    return !this->utf8Character.empty() || (this->utf8Character.empty() && this->isEndOfFile());
}

bool UTF8Character::isAlphaNumeric() const
{
    return this->isValid() && (this->utf8Character.size() > 1 || isalnum(this->toInteger()));
}

bool UTF8Character::isNumeric() const
{
    return this->isValid() && this->utf8Character.size() == 1 && isdigit(this->toInteger());
}

bool UTF8Character::isAlphabet() const
{
    return this->isValid() && (this->utf8Character.size() > 1 || isalpha(this->toInteger()));
}

bool UTF8Character::isBlank() const
{
    return this->isValid() && this->utf8Character.size() == 1 && isblank(this->toInteger());
}

bool UTF8Character::isSpace() const
{
    return this->isValid() && this->utf8Character.size() == 1 && isspace(this->toInteger());
}

bool UTF8Character::isControl() const
{
    return this->isValid() && this->utf8Character.size() == 1 && iscntrl(this->toInteger());
}

bool UTF8Character::isEndOfFile() const
{
    return this->endOfFile;
}

bool UTF8Character::operator==(const UTF8Character &other) const
{
    return this->utf8Character == other.utf8Character;
}

bool UTF8Character::operator==(const std::__cxx11::string &other) const
{
    return this->utf8Character == other;
}

bool UTF8Character::operator==(char other) const
{
    UTF8Character o(other);
    return (*this) == o;
}

bool UTF8Character::operator!=(const UTF8Character &other) const
{
    return !((*this) == other);
}

bool UTF8Character::operator!=(const std::__cxx11::string &other) const
{
    return !((*this) == other);
}

bool UTF8Character::operator!=(char other) const
{
    return !((*this) == other);
}

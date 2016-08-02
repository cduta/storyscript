#ifndef __UTF8_CHARACTER_HPP__
#define __UTF8_CHARACTER_HPP__

#include <string>
#include <ostream>

class UTF8Character
{
    std::string utf8Character;
    bool endOfFile;

public:
    UTF8Character(bool isEndOfFile = false);
    explicit UTF8Character(char c1);
    explicit UTF8Character(char c1, char c2);
    explicit UTF8Character(char c1, char c2, char c3);
    explicit UTF8Character(char c1, char c2, char c3, char c4);

    static int characterSize(char c);

    int toInteger() const;

    // Get-Method
    std::string toString() const;
    int getCharacterSize() const;
    bool isValid() const;
    bool isAlphaNumeric() const;
    bool isNumeric() const;
    bool isAlphabet() const;
    bool isBlank() const;
    bool isSpace() const;
    bool isControl() const;
    bool isEndOfFile() const;

    // Operators
    std::ostream& operator<<(std::ostream& ostream)
    {
        for(int i = 0; i < this->utf8Character.size(); ++i)
        {
            ostream << this->utf8Character.at(i);
        }

        return ostream;
    }

    bool operator==(char other) const;
    bool operator==(const std::string &other) const;
    bool operator==(const UTF8Character &other) const;

    bool operator!=(char other) const;
    bool operator!=(const std::string &other) const;
    bool operator!=(const UTF8Character &other) const;
};

#endif

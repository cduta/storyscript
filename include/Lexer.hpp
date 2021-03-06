#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#include <fstream>
#include <tuple>
#include <vector>

#include "Tokens/Token.hpp"

class Lexer
{
public:
    static Token *getToken(std::istream &stream);
    static std::vector<Token *> tokenize(std::istream &stream);
};

#endif

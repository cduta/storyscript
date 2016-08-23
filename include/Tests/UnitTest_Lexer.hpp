#ifndef __UNIT_TEST___LEXER_HPP__
#define __UNIT_TEST___LEXER_HPP__

#include <gtest/gtest.h>
#include <cctype>
#include <sstream>

#include "../UTF8Character.hpp"
#include "../UTF8IStream.hpp"
#include "../Lexer.hpp"

TEST(UTF8CharacterTest, Ascii)
{
    const char *ascii = "a";
    UTF8Character asciiUTF8Char(ascii[0]);
    EXPECT_TRUE(asciiUTF8Char.isValid());
    EXPECT_EQ(asciiUTF8Char.toInteger(), (int)'a');
    EXPECT_TRUE(asciiUTF8Char.isAlphaNumeric());
}

TEST(UTF8CharacterTest, AsciiUTF8)
{
    const char *asciiUTF8 = u8"\u0042";
    UTF8Character asciiUTF8UTF8Char(asciiUTF8[0]);
    EXPECT_TRUE(asciiUTF8UTF8Char.isValid());
    EXPECT_EQ(asciiUTF8UTF8Char.toInteger(), 0x42);
    EXPECT_TRUE(asciiUTF8UTF8Char.isAlphaNumeric());
}

TEST(UTF8CharacterTest, UTF8TwoByte)
{
    const char *UTF8TwoByte = u8"\u07FE";
    UTF8Character asciiTwoByteUTF8Char(UTF8TwoByte[0], UTF8TwoByte[1]);
    EXPECT_TRUE(asciiTwoByteUTF8Char.isValid());
    EXPECT_EQ(asciiTwoByteUTF8Char.toInteger(), 0xBEDF);
    EXPECT_TRUE(asciiTwoByteUTF8Char.isAlphaNumeric());
}

TEST(UTF8CharacterTest, UTF8ThreeByte)
{
    const char *UTF8ThreeByte = u8"\uFFFE";
    UTF8Character asciiThreeByteUTF8Char(UTF8ThreeByte[0], UTF8ThreeByte[1], UTF8ThreeByte[2]);
    EXPECT_TRUE(asciiThreeByteUTF8Char.isValid());
    EXPECT_EQ(asciiThreeByteUTF8Char.toInteger(), 0xBEBFEF);
    EXPECT_TRUE(asciiThreeByteUTF8Char.isAlphaNumeric());
}

TEST(UTF8CharacterTest, UTF8FourByte)
{
    const char *UTF8FourByte = u8"\U0010FFFE";
    UTF8Character asciiFourByteUTF8Char(UTF8FourByte[0], UTF8FourByte[1], UTF8FourByte[2], UTF8FourByte[3]);
    EXPECT_TRUE(asciiFourByteUTF8Char.isValid());
    EXPECT_EQ(asciiFourByteUTF8Char.toInteger(), 0xBEBF8FF4);
    EXPECT_TRUE(asciiFourByteUTF8Char.isAlphaNumeric());
}

TEST(UTF8CharacterTest, NumberTest)
{
    const char *ascii = "a1";
    UTF8Character asciiUTF8Char(ascii[0]);
    EXPECT_TRUE(asciiUTF8Char.isValid());
    EXPECT_FALSE(asciiUTF8Char.isNumeric());
    UTF8Character asciiUTF8Number(ascii[1]);
    EXPECT_TRUE(asciiUTF8Number.isValid());
    EXPECT_TRUE(asciiUTF8Number.isNumeric());
}

TEST(UTF8IStreamTest, GetAndPutBack)
{
    std::stringstream sstream;

    sstream << u8"ab\u0123d";

    UTF8IStream utf8Stream(sstream);

    UTF8Character utf8Character = utf8Stream.getChar();

    EXPECT_EQ(utf8Character, UTF8Character('a'));

    utf8Stream.ungetChar(utf8Character.getCharacterSize());
    utf8Character = utf8Stream.getChar();

    EXPECT_EQ(utf8Character, UTF8Character('a'));

    utf8Character = utf8Stream.getChar();
    utf8Character = utf8Stream.getChar();

    EXPECT_EQ(utf8Character.toInteger(), 0xa3c4);

    utf8Stream.ungetChar(utf8Character.getCharacterSize());
    utf8Character = utf8Stream.getChar();

    EXPECT_EQ(utf8Character.toInteger(), 0xa3c4);
}

TEST(UTF8LexerTest, TokenizeOne)
{
    std::stringstream sstream;
    sstream << u8"abcd\u0123";

    std::vector<Token *> tokens = Lexer::tokenize(sstream);

    EXPECT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0]->getType(), Token::IDENTIFIER);
    EXPECT_EQ(tokens[1]->getType(), Token::END_OF_FILE);
}

TEST(UTF8LexerTest, TokenizeTwo)
{
    std::stringstream sstream;
    sstream << u8"abcd\u0123 123456";

    std::vector<Token *> tokens = Lexer::tokenize(sstream);

    EXPECT_EQ(tokens.size(), 3);
    EXPECT_EQ(tokens[0]->getType(), Token::IDENTIFIER);
    EXPECT_EQ(tokens[1]->getType(), Token::INTEGER);
    EXPECT_EQ(tokens[2]->getType(), Token::END_OF_FILE);
}

TEST(UTF8LexerTest, TokenizeTwoWithCommentInBetween)
{
    std::stringstream sstream;
    sstream << u8"abcd\u0123 /* THIS IS A COMMENT! */ 123456";

    std::vector<Token *> tokens = Lexer::tokenize(sstream);

    EXPECT_EQ(tokens.size(), 3);
    EXPECT_EQ(tokens[0]->getType(), Token::IDENTIFIER);
    EXPECT_EQ(tokens[1]->getType(), Token::INTEGER);
    EXPECT_EQ(tokens[2]->getType(), Token::END_OF_FILE);
}

#endif

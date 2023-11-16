/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2023 Nathan Osman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "exception.hpp"
#include "lexer.hpp"

using namespace StateSrv::StateLang;

Lexer::Lexer(const std::wstring &filename)
    : mStream(filename)
{
}

wchar_t Lexer::getNextChar(bool eofAllowed) {
    int v = mStream.get();
    if (v == EOF && !eofAllowed) {
        throw CompilerErrorException(L"unexpected EOF");
    }
    return static_cast<wchar_t>(v);
}

std::unique_ptr<Token> Lexer::parseStringLiteral()
{
    std::wstring value;
    while (true) {
        wchar_t v = parseCharacter();
        if (v == L'"') {
            return std::make_unique<StringLiteralToken>(value);
        }
        value.push_back(v);
    }
}

std::unique_ptr<Token> Lexer::parseNumberLiteral()
{
    //...
    return nullptr;
}

std::unique_ptr<Token> Lexer::parseIdentifier()
{
    //...
    return nullptr;
}

std::unique_ptr<Token> Lexer::parseOperator()
{
    //...
    return nullptr;
}

wchar_t Lexer::parseCharacter()
{
    wchar_t v = getNextChar(false);
    if (v == L'\\') {
        switch (getNextChar(false)) {
        case L't': return L'\t';
        case L'n': return L'\n';
        default:
            throw CompilerErrorException(L"invalid escape sequence");
        }
    }
    return v;
}

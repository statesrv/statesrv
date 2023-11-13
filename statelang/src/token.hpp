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

#ifndef STATESRV_STATELANG_TOKEN_H
#define STATESRV_STATELANG_TOKEN_H

#include <string>

namespace StateSrv
{
namespace StateLang
{

enum TokenType {
    TStringLiteral,
    TIntLiteral,
    TFloatLiteral,
    TKeyword,
    TIdentifier,
    TOperator
};

enum Keyword {
    KBool,
    KBreak,
    KCase,
    KContinue,
    KDefault,
    KElse,
    KEnum,
    KFalse,
    KFloat,
    KFunction,
    KIf,
    KMutator,
    KState,
    KString,
    KStruct,
    KSwitch,
    KTrue,
    KVar,
    KWhile
};

enum Operator {
    ONegate,
    ONot,
    OMultiply,
    ODivide,
    OModulo,
    OAdd,
    OSubtract,
    OLessThan,
    OLessThanOrEqual,
    OGreaterThan,
    OGreaterThanOrEqual,
    OEqual,
    ONotEqual,
    OAnd,
    OOr,
    OAssignment
};

/**
 * @brief A lexical element from an input stream
 */
class Token
{
public:

    TokenType type() const { return mType; }

protected:

    TokenType mType;
};

/**
 * @brief Base template class for typed tokens
 */
template <typename T>
class BaseToken : public Token
{
public:

    explicit BaseToken(const T &value) { mValue(value); }

    T value() const { return mValue; }

private:

    T mValue;
};

class StringLiteralToken : public BaseToken<std::wstring>
{};

class IntLiteralToken : public BaseToken<int>
{};

class FloatLiteralToken : public BaseToken<float>
{};

class KeywordToken : public BaseToken<Keyword>
{};

class IdentifierToken : public BaseToken<std::wstring>
{};

class OperatorToken : public BaseToken<Operator>
{};

}
}

#endif // STATESRV_STATELANG_TOKEN_H

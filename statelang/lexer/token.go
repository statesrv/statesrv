package lexer

type TokenType int

const (
	TStringLiteral TokenType = iota
	TIntLiteral
	TFloatLiteral
	TKeyword
	TIdentifier
	TOperator
)

type Keyword int

const (
	KBool Keyword = iota
	KBreak
	KCase
	KContinue
	KDefault
	KElse
	KEnum
	KFalse
	KFloat
	KFunction
	KIf
	KMutator
	KState
	KString
	KStruct
	KSwitch
	KTrue
	KVar
	KWhile
)

type Operator int

const (
	ONot Operator = iota
	OMultiply
	ODivide
	OModulo
	OAddOrPositive
	OSubtractOrNegative
	OLessThan
	OLessThanOrEqual
	OGreaterThan
	OGreaterThanOrEqual
	OEqual
	ONotEqual
	OAnd
	OOr
	OAssignment
)

// Token represents a lexical token in a source file. The Type member indicates
// what is stored in the Value member.
type Token struct {
	Type  TokenType
	Value any
}

// String returns the value of the token as a string. This should only be
// called when Type is equal to TStringLiteral or TIdentifier.
func (t *Token) String() string {
	return t.Value.(string)
}

// Int32 returns the value of the token as an int32. This should only be called
// when Type is equal to TIntLiteral.
func (t *Token) Int() int32 {
	return t.Value.(int32)
}

// Float returns the value of the token as a float32. This should only be
// called when Type is equal to TFloatLiteral.
func (t *Token) Float32() float32 {
	return t.Value.(float32)
}

// Keyword returns the value of the token as a Keyword. This should only be
// called when Type is equal to TKeyword.
func (t *Token) Keyword() Keyword {
	return t.Value.(Keyword)
}

// Operator returns the value of the token as an Operator. This should only be
// called when Type is equal to TOperator.
func (t *Token) Operator() Operator {
	return t.Value.(Operator)
}

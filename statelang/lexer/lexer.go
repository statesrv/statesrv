package lexer

import (
	"bufio"
	"fmt"
	"io"
	"slices"
)

var (
	whitespaceCharacters = []rune{
		' ', '\t', '\r', '\n',
	}
	keywordMap = map[string]Keyword{
		"bool":     KBool,
		"break":    KBreak,
		"case":     KCase,
		"continue": KContinue,
		"default":  KDefault,
		"else":     KElse,
		"enum":     KEnum,
		"false":    KFalse,
		"float":    KFloat,
		"function": KFunction,
		"if":       KIf,
		"mutator":  KMutator,
		"state":    KState,
		"string":   KString,
		"struct":   KStruct,
		"switch":   KSwitch,
		"true":     KTrue,
		"var":      KVar,
		"while":    KWhile,
	}
	operatorFirstCharacter = []rune{
		'-', '!', '*', '/', '%', '+', '<', '>', '=', '&', '|',
	}
	operatorMap = map[string]Operator{
		"!":  ONot,
		"*":  OMultiply,
		"/":  ODivide,
		"%":  OModulo,
		"+":  OAddOrPositive,
		"-":  OSubtractOrNegative,
		"<":  OLessThan,
		"<=": OLessThanOrEqual,
		">":  OGreaterThan,
		">=": OGreaterThanOrEqual,
		"==": OEqual,
		"!=": ONotEqual,
		"&&": OAnd,
		"||": OOr,
		"=":  OAssignment,
	}
)

// Lexer reads an input stream and produces lexical tokens.
type Lexer struct {
	reader *bufio.Reader
	c      rune
}

func (l *Lexer) advance() error {
	r, _, err := l.reader.ReadRune()
	if err != nil {
		return err
	}
	l.c = r
	return nil
}

func (l *Lexer) parseStringLiteral() (*Token, error) {
	return nil, nil
}

func (l *Lexer) parseNumberLiteral() (*Token, error) {
	return nil, nil
}

func (l *Lexer) parseIdentifier() (*Token, error) {
	return nil, nil
}

func (l *Lexer) parseOperator() (*Token, error) {
	return nil, nil
}

// New creates a new Lexer from the provided reader.
func New(r io.Reader) *Lexer {
	return &Lexer{
		reader: bufio.NewReader(r),
	}
}

// GetNextToken retrieves the next token from the input stream.
func (l *Lexer) GetNextToken() (*Token, error) {

	// If this is the first call, fetch the first token
	if l.c == 0 {
		if err := l.advance(); err != nil {
			return nil, err
		}
	}

	// Skip over whitespace
	for slices.Contains(whitespaceCharacters, l.c) {
		if err := l.advance(); err != nil {
			return nil, err
		}
	}

	// Use the appropriate method to extract the token
	switch {
	case l.c == '"':
		return l.parseStringLiteral()
	case l.c >= '0' && l.c <= '9':
		return l.parseNumberLiteral()
	case l.c >= 'A' && l.c <= 'Z' || l.c >= 'a' && l.c <= 'z' || l.c == '_':
		return l.parseIdentifier()
	case slices.Contains(operatorFirstCharacter, l.c):
		return l.parseOperator()
	default:
		return nil, fmt.Errorf("unrecognized character \"%c\"", l.c)
	}
}

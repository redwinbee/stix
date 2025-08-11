#ifndef stix_scanner_h
#define stix_scanner_h

typedef enum {
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    TOKEN_LEFT_BRACE,
    TOKEN_RIGHT_BRACE,
    TOKEN_COMMA,
    TOKEN_DOT,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_SEMICOLON,
    TOKEN_SLASH,
    TOKEN_STAR,
    TOKEN_BANG,
    TOKEN_BANG_EQUAL,
    TOKEN_EQUAL,
    TOKEN_EQUAL_EQUAL,
    TOKEN_GREATER,
    TOKEN_GREATER_EQUAL,
    TOKEN_LESS,
    TOKEN_LESS_EQUAL,
    TOKEN_IDENTIFIER,
    TOKEN_STRING,
    TOKEN_NUMBER,
    TOKEN_AND,
    TOKEN_CLASS,
    TOKEN_ELSE,
    TOKEN_FALSE,
    TOKEN_FOR,
    TOKEN_FN,
    TOKEN_IF,
    TOKEN_NIL,
    TOKEN_OR,
    TOKEN_PRINT,
    TOKEN_RETURN,
    TOKEN_SUPER,
    TOKEN_THIS,
    TOKEN_TRUE,
    TOKEN_VAR,
    TOKEN_WHILE,
    TOKEN_ERROR,
    TOKEN_EOF
} token_type;

typedef struct {
    token_type type;
    const char *start;
    int length;
    int line;
} token_t;

void init_scanner(const char *source);
token_t scan_token();
bool is_at_end();
bool is_digit(char c);
bool is_alpha(char c);
token_t make_token(token_type type);
token_t error_token(const char *message);
char advance(void);
bool match(char expected);
void skip_whitespace(void);
char peek(void);
char peek_next(void);
token_t string(void);
token_t number(void);
token_t identifier(void);
token_type identifier_type(void);
token_type check_keyword(int length, const char *remaining, token_type type);

#endif

grammar OPLang;

@lexer::header {
from lexererr import *
}

@lexer::members {
def emit(self):
    tk = self.type
    if tk == self.UNCLOSE_STRING:       
        result = super().emit();
        text = result.text[1:] if result.text.startswith('"') else result.text
        raise UncloseString(text);
    elif tk == self.ILLEGAL_ESCAPE:
        result = super().emit();
        raise IllegalEscape(result.text);
    elif tk == self.ERROR_CHAR:
        result = super().emit();
        raise ErrorToken(result.text); 
    else:
        return super().emit();
}

options{
	language=Python3;
}

program: classlist EOF;
  // : (assignment)* EOF; // write for program rule here using vardecl and funcdecl

classlist: clas classlist | clas; // 1 or more classes

// CLASS DECL
clas: CLASS ID (EXTENDS ID)? LBRACE members RBRACE;

// MEMBER OF CLASS
members: member members | ;

member
  : attributedecl
  | methoddecl
  | constructor
  | destructor
  ;

// ATTRIBUTE DECL
attributedecl: attrmods type AMP? attributelist SEMI;
attributelist: attribute COMMA attributelist | attribute;
attribute: ID (ASSIGN expr)?;
attrmods
  : STATIC
  | FINAL
  | STATIC FINAL
  | FINAL STATIC
  |
  ;

// METHOD DECL
methoddecl: STATIC? typevoid AMP? ID LPAREN paramlist RPAREN blockstmt;

// PARAM OF A METHOD
paramlist: paramprime | ;
paramprime: param SEMI paramprime | param;
param: type AMP? idlist;

// ID LIST 
idlist: ID COMMA idlist | ID;

// STATEMENT LIST
stmtlist: stmt stmtlist | ;
stmt 
  : blockstmt
  | vardecl
  | assignstmt
  | ifstmt
  | forstmt
  | breakstmt
  | continuestmt
  | returnstmt
  | methodinvokestmt
  ;
// BLOCK LIST
blockstmt: LBRACE stmtlist RBRACE;
vardecl
  : FINAL? type varlist SEMI
  | FINAL? type AMP varlist2 SEMI
  ;
varlist: varitem | varitem COMMA varlist;
varitem: ID (ASSIGN expr)?;

varlist2: varitem2 | varitem2 COMMA varlist2;
varitem2: ID ASSIGN expr;

assignstmt
  : post_expr ASSIGN expr SEMI 
  // | type AMP? assignlist SEMI
  // | ID ASSIGN expr
  ;

assignlist: assignonce COMMA assignlist | assignonce;
assignonce: ID ASSIGN expr;

ifstmt: IF expr THEN stmt (ELSE stmt)?;
forstmt: FOR ID ASSIGN expr (TO | DOWNTO) expr DO stmt;
breakstmt: BREAK SEMI;
continuestmt: CONTINUE SEMI;
returnstmt: RETURN expr? SEMI;
methodinvokestmt: expr DOT ID LPAREN arg_list RPAREN SEMI; // update

// TYPE DECL 
type: base_type type_array_suff;
typevoid
  : base_type type_array_suff
  | (base_type | VOID)
  ;
// type_array_suff: LBRACK INT RBRACK type_array_suff | ;
type_array_suff: LBRACK INT RBRACK | ;
base_type: (INT_LIT | FLOAT_LIT | BOOL_LIT | STRING_LIT | ID);

// CONSTRUCTORS DECL
// constructor: default_constructor | user_constructor;  // | copy_constructor; 
constructor: ID LPAREN paramlist RPAREN blockstmt;

// DESTRUCTOR DECL
destructor: TILDE ID LPAREN RPAREN blockstmt;

// EXPR
// expr : or_expr;
// or_expr: and_expr or_expr_tail;
// or_expr_tail: OR_OR and_expr or_expr_tail | ;

// orand_expr: eq_expr orand_expr_tail;
// orand_expr_tail: (OR_OR | AND_AND) eq_expr orand_expr_tail | ;
// eq_expr: relational_expr eq_expr_tail;
// eq_expr_tail: (EQEQ | NEQ) relational_expr | ;
// relational_expr: addsub_expr relational_expr_tail;
// relational_expr_tail: (LT | GT | GE | LE) addsub_expr | ;
expr : relational_expr;
relational_expr: eq_expr relational_expr_tail;
relational_expr_tail: (LT | GT | GE | LE) eq_expr | ;
eq_expr: orand_expr eq_expr_tail;
eq_expr_tail: (EQEQ | NEQ) orand_expr | ;
orand_expr: orand_expr (OR_OR | AND_AND) addsub_expr | addsub_expr;
// orand_expr_tail: (OR_OR | AND_AND) addsub_expr orand_expr_tail | ;

addsub_expr: addsub_expr (PLUS | MINUS) muldiv_expr | muldiv_expr;
muldiv_expr: muldiv_expr (STAR | SLASH | PERCENT | BACKSLASH) caret_expr | caret_expr;
caret_expr: caret_expr CARET unary_expr | unary_expr;
unary_expr
  : (PLUS | MINUS) unary_expr
  | BANG unary_expr
  | post_expr
  ;

post_expr: primary post_expr_tail ;
post_expr_tail: post_suffix post_expr_tail | ;

post_suffix
  : DOT ID method_call_args_opt
  | DOT ID
  | LBRACK expr RBRACK
  ;

method_call_args_opt: LPAREN arg_list RPAREN;

primary
  : INT 
  | FLOAT 
  | STRING 
  | BOOLEAN
  | NIL
  | ID 
  | THIS
  | LPAREN expr RPAREN
  | class_create_expr
  | array_expr
  ;

class_create_expr: NEW ID LPAREN arg_list RPAREN;
arg_list: arg_list_prime | ;
arg_list_prime: expr COMMA arg_list_prime | expr;
array_access: LBRACK expr RBRACK;

array_expr: LBRACE expr_list RBRACE;

expr_list: exprprime | ;
exprprime: expr COMMA exprprime | expr;

// LEXER RULE
LINE_COMMENT: '#' (~[\r\n])* -> skip; 
BLOCK_COMMENT  : '/*' .*? '*/'-> skip;

SLASH :'/';
BACKSLASH :'\\';
ILLEGAL_ESCAPE
  : '"' 
    ('\\' VALID_ESC | NOT_NEWLINE)* 
    '\\' ILLEGAL_ESC
  { 
    if self.text.startswith('"'):
      self.text = self.text[1:] 
    if self.text.endswith('"'):
      self.text = self.text[:-1]
  }
  ; // no \ " \r \n

UNCLOSE_STRING
  : '"' ( '\\' VALID_ESC | NOT_NEWLINE )* ('\r'? '\n' | EOF)   /// \r\n or \n or EOF
  { 
    if self.text.startswith('"'):
      self.text = self.text[1:] 
  }
  ;

STRING
  : '"' ( '\\' VALID_ESC | NOT_NEWLINE )* '"'
  { 
    if self.text.startswith('"'):
      self.text = self.text[1:] 
    if self.text.endswith('"'):
      self.text = self.text[:-1]
  }
  ;

fragment NOT_NEWLINE: ~[\\"\r\n]; //  \ " \r and \n (\ because it has already been handled in the LHS)
fragment VALID_ESC: [btnfr"\\]; // \b \t \b \f \r \" \\
fragment ILLEGAL_ESC: ~[btnfr"\\\r\n]; 

INT : [0-9]+ ;
FLOAT 
: [0-9]+ '.' [0-9]* (EXPONENT)?
| [0-9]+ EXPONENT
;
BOOLEAN: (TRUE_KW | FALSE_KW);
fragment EXPONENT: [Ee] [+-]? [0-9]+;

// EQ : '=';
BOOL_LIT : 'boolean' ;
BREAK : 'break' ;
CLASS : 'class' ;
CONTINUE:'continue';
DO :'do';
ELSE :'else';
EXTENDS :'extends';
FLOAT_LIT :'float';
IF :'if';
INT_LIT :'int';
STRING_LIT :'string';
THEN :'then';
FOR :'for';
RETURN :'return';
TRUE_KW :'true';
FALSE_KW :'false';
VOID :'void';
NIL :'nil';
THIS :'this';
FINAL : 'final';
STATIC :'static';
TO :'to';
DOWNTO :'downto';

WS : [ \t\r\n\f]+ -> skip ; // skip spaces, tabs 

NEQ :'!=';
LE :'<=';
GE :'>=';
AND_AND :'&&';
OR_OR :'||';
EQEQ :'==';

PLUS :'+';
MINUS :'-';
STAR :'*';
PERCENT :'%';
CARET :'^';
LT :'<';
GT :'>';
BANG :'!';

LBRACK :'[';
RBRACK :']';
LBRACE :'{';
RBRACE :'}';
LPAREN :'(';
RPAREN :')';
COLON :':';
SEMI :';';
DOT :'.';
COMMA :',';

TILDE :'~';
AMP :'&';
NEW :'new';
// Add new rule
ID  : ([a-zA-Z_] [a-zA-Z0-9_]*);
ASSIGN: ':=';

ERROR_CHAR: .;


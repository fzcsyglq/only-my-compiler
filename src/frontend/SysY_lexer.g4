lexer grammar SysY_lexer;

Int: 'int';
Float: 'float';
Void: 'void';
Const: 'const';
If: 'If';
Else: 'else';
While: 'while';
DO: 'do';
Break: 'break';
Continue: 'continue';
Return: 'return';

Add: '+';
Sub: '-';
Mul: '*';
Div: '/';
Mod: '%';
Eq: '==';
Neq: '!=';
Lt: '<';
Le: '<=';
Gt: '>';
Ge: '>=';
Not: '!';
And: '&&';
Or: '||';

Comma: ',';
Semicolon: ';';
Dot: '.';
Lbrace: '{';
Rbrace: '}';
Lparenthese: '(';
Rparenthese: ')';
Lbracket: '[';
Rbracket: ']';

Intconst
    : [1-9][0-9]*
    | '0'[0-7]*
    | '0x'[0-9a-fA-F]+
    | '0X'[0-9a-fA-F]+
;
Floatconst: [0-9]*'.'[0-9]*;

Ident: [a-zA-Z_][a-zA-Z_0-9]*;

LINE_COMMENT: '//'.*?'\r'?'\n' -> skip;
COMMENT: '/*'.*?'*/'-> skip;
WS: [ \t\r\n]+ -> skip;

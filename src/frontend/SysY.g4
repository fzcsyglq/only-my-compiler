grammar SysY;

import SysY_lexer;

compUnit: (decl | funcDef)* EOF;

decl: constDecl | varDecl;

constDecl: 'const' bType constDef (',' constDef)* ';';

bType: 'int' | 'float';

constDef: Ident ('[' constExp ']')* '=' constInitVal;

constInitVal
    : constExp
    | '{' initVal (',' initVal)* '}'
;

varDecl: bType varDef (',' varDef)* ';';

varDef
    : Ident ('[' constExp ']')*
    | Ident ('[' constExp ']')* '=' initVal
;

initVal
    : exp
    | '{' (initVal (',' initVal)*)? '}'
;

funcDef: funcType Ident '(' (funcFParams)? ')' block;

funcType: 'void' | 'int' | 'float';

funcFParams: funcFParam (',' funcFParam)*;

funcFParam: bType Ident ('['']' ('[' exp ']')*)?;

block: '{' (blockItem)* '}';

blockItem: decl | stmt;

stmt
    : lVal '=' exp ';' #StmtAssignment
    | (exp)? ';' #StmtExp
    | block #StmtBlock
    | 'if' '(' cond ')' stmt ('else' stmt)? #StmtIf
    | 'while' '(' cond ')' stmt #StmtWhile
    | 'break' ';' #StmtBreak
    | 'continue' ';' #StmtContinue
    | 'return' (exp)? ';' #StmtReturn
;

exp: addExp;

cond: lOrExp;

lVal: Ident ('[' exp ']')*;

primaryExp
    : '(' exp ')' #PrimaryExp1
    | lVal #PrimaryExp2
    | number #PrimaryExp3
    ;

number: Intconst | Floatconst;

unaryExp
    : primaryExp
    | Ident '(' (funcRParams)? ')'
    | unaryOp unaryExp
;

unaryOp: '+' | '-' | '!';

funcRParams: exp (',' exp)*;

mulExp
    : unaryExp 
    | mulExp ('*' | '/' '%') unaryExp
    ;

addExp
    : mulExp
    | addExp ('+' | '-') mulExp
;

relExp
    : addExp
    | relExp ('<' | '>' | '<=' | '>=') addExp
;

eqExp
    : relExp
    | eqExp ('==' | '!=') relExp
;

lAndExp
    : eqExp
    | lAndExp '&&' eqExp
;

lOrExp
    : lAndExp
    | lOrExp '||' lAndExp
;

constExp: addExp;
    
%{
#include <string>
#include <vector>
#include <iostream>

#include "problem.h"
#include "literal.h"
#include "integervalue.h"
#include "boolvalue.h"
#include "variableidentifier.h"
#include "addoperation.h"
#include "multoperation.h"
#include "divoperation.h"
#include "suboperation.h"
#include "ltoperation.h"
#include "gtoperation.h"
#include "geoperation.h"
#include "leoperation.h"
#include "eqoperation.h"
#include "neoperation.h"
#include "setliteral.h"

extern int yylex();
void yyerror(Problem** problem, const char* message) {
    std::cerr << message;
};
%}
%parse-param {Problem **problem}

%union { 
    int i; 
    std::string *s; 
    Expression* e; 
    Variable* v; 
    VariableSet* vs;
    Constraint* c; 
    ConstraintSet* cs;
    std::vector<Expression*>* es;
}

%token tPROBLEM tWITH tCONSTRAINT tVARIABLE tDOMAIN tTRUE tFALSE
%token tEQ tGE tLE tNE
%token<i> tINTEGER
%token<s> tIDENTIFIER
%type<e> expression variable_id set_literal
%type<v> variable
%type<c> constraint
%type<cs> constraints
%type<vs> variables
%type<es> expression_list


%left '>' '<' tEQ tGE tLE tNE
%left '+' '-'
%left '*' '/' '%'
%start problem
%%

problem : tPROBLEM tIDENTIFIER '{' variables constraints '}' { (*problem) = new Problem (*$2, $4, $5); }
        ;
        
variables  : variable            { $$ = new VariableSet (); $$->add($1); }
           | variables variable  { $$ = $1; $$->add ($2);  }
           ;
                
constraints : constraint                { $$ = new ConstraintSet (); $$->add($1); }
            | constraints constraint    { $$ = $1; $$->add ($2); }
            ;
            
/* TODO add types to variable definitions */            
variable : tVARIABLE tIDENTIFIER tWITH tDOMAIN expression ';' { $$ = new Variable ($5, &Type::INTEGER, *$2); }
         ;

constraint : tCONSTRAINT expression ';' { $$ = new Constraint($2); }
           ;
           
expression : expression '+' expression  { $$ = new AddOperation ($1, $3); }
           | expression '-' expression  { $$ = new SubOperation ($1, $3); }
           | expression '*' expression  { $$ = new MultOperation ($1, $3); }
           | expression '/' expression  { $$ = new DivOperation($1, $3); }
           | expression '<' expression  { $$ = new LtOperation ($1, $3); }
           | expression '>' expression  { $$ = new GtOperation ($1, $3); }
           | expression tEQ expression  { $$ = new EqOperation ($1, $3); }
           | expression tGE expression  { $$ = new GeOperation ($1, $3); }
           | expression tLE expression  { $$ = new LeOperation ($1, $3); }
           | expression tNE expression  { $$ = new NeOperation ($1, $3); }
           | tINTEGER                   { $$ = new Literal(new IntegerValue ($1)); }
           | tTRUE                      { $$ = new Literal(new BoolValue (true)); }
           | tFALSE                     { $$ = new Literal(new BoolValue (false)); }
           | variable_id                { $$ = $1; }
           | set_literal                { $$ = $1; }
           | '(' expression ')'         { $$ = $2; }
           ;
           
variable_id : tIDENTIFIER { $$ = new VariableIdentifier (*$1); }
            ;
            
set_literal : '{' expression_list '}'   { $$ = new SetLiteral ($2); }
            | '{' '}'                   { $$ = new SetLiteral ();}
            ;
    
expression_list : expression { $$ = new std::vector<Expression*> (); $$->push_back($1); }
                | expression_list expression { $$ = $1; $$->push_back($2); }
                ;
%%

%{
#include <string>
#include <iostream>
#include "problem.h"
#include "literal.h"
#include "integervalue.h"
#include "variableidentifier.h"
#include "addoperation.h"
#include "setliteral.h"
#include <map>

//fixme does not need to be global. problem->addVariable, problem->searchVariable,
static std::map<std::string, int> map;
static int globalFixme = 0;
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

%token tPROBLEM tWITH tCONSTRAINT tVARIABLE tDOMAIN
%token<i> tINTEGER
%token<s> tIDENTIFIER
%type<e> expression variable_id set_literal
%type<v> variable
%type<c> constraint
%type<cs> constraints
%type<vs> variables
%type<es> expression_list


%left '>' '<'
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
           | expression '-' expression  {}
           | expression '*' expression  {}
           | expression '/' expression  {}
           | expression '>' expression  {}
           | expression '<' expression  {}
           | tINTEGER                   { $$ = new Literal(new IntegerValue (tINTEGER)); }
           | variable_id                { $$ = $1;}
           | set_literal                { $$ = $1;}
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

%{
#include <string>
#include <iostream>
#include "problem.h"
#include "literal.h"
#include "integervalue.h"
#include "variableidentifier.h"
#include "addoperation.h"
#include <map>

//fixme does not need to be global. problem->addVariable, problem->searchVariable,
static std::map<std::string, int> map;
static int globalFixme = 0;
extern int yylex();
void yyerror(Problem* problem, const char* message) {
    std::cerr << message;
};
%}
%parse-param {Problem *problem}
%union { int i; std::string *s; Expression* e; Variable* var; Constraint* c; }

%token tPROBLEM tWITH tCONSTRAINT tVARIABLE tDOMAIN
%token<i> tINTEGER
%token<s> tIDENTIFIER
%type<e> expression variable_id 
%type<var> variable
%type<c> constraint

%right '='
%left '+' '-'
%left '*' '/' '%'
%start problem
%%
problem : tPROBLEM tIDENTIFIER ':' variables constraints
        ;
        
variables  : variable                  { problem->addVariable($1); }
           | variables variable   { problem->addVariable($2); }
           ;
                
constraints : constraint                { problem->addConstraint($1); }
            | constraints constraint    { problem->addConstraint($2); }
            ;
            
variable : tVARIABLE tIDENTIFIER tWITH tDOMAIN expression { $$ = new Variable ($5, &Type::INTEGER, *$2); }
         ;

constraint : tCONSTRAINT expression  { $$ = new Constraint($2); }
           ;
           
expression : expression '+' expression  { $$ = new AddOperation ($1, $3); }
           | expression '-' expression  {}
           | expression '*' expression  {}
           | expression '/' expression  {}
           | tINTEGER                   { $$ = new Literal(new IntegerValue (tINTEGER)); }
           | variable_id                { $$ = $1;}
           ;
           
variable_id : tIDENTIFIER { $$ = new VariableIdentifier (problem->searchVariableId(*$1)); }
%%

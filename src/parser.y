%{
#include <string>
#include <iostream>
#include "problem.h"
#include "literal.h"
#include "integervalue.h"
#include "variableidentifier.h"
#include "addoperation.h"
#include <map>

static std::map<std::string, int> map;
static int globalFixme = 0;
extern int yylex();
void yyerror(const char* message) {
    std::cerr << message;
};
%}

%union { int i; std::string *s; Expression* e; VariableDefinition* vdef; VariablesDefinitions* vdefs; Constraint* c; ConstraintSet* cs;}

%token tPROBLEM tWITH tCONSTRAINT tVARIABLE tDOMAIN
%token<i> tINTEGER
%token<s> tIDENTIFIER
%type<e> expression variable_id 
%type<vdef> variable_def
%type<vdefs> variables_defs
%type<c> constraint
%type<cs> constraints

%right '='
%left '+' '-'
%left '*' '/' '%'
%start problem
%%
problem : tPROBLEM tIDENTIFIER ':' variables_defs constraints
        ;
        
variables_defs  : variable_def                  { $$ = new VariablesDefinitions (); $$->add($1); }
                | variables_defs variable_def   { $$ = $1; $$->add($2); }
                ;
                
constraints : constraint                { $$ = new ConstraintSet (); $$->add($1); }
            | constraints constraint    { $$ = $1; $$->add($2); }
            ;
            
variable_def : tVARIABLE tIDENTIFIER tWITH tDOMAIN expression { $$ = new VariableDefinition ($5, nullptr, globalFixme++); }
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
           
variable_id : tIDENTIFIER { $$ = new VariableIdentifier (globalFixme++); }
%%
int main () {
    yyparse();
}

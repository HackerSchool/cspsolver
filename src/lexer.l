%option noyywrap
%{
#include <cstdlib>
#include <string>
#include "problem.h"
#include "y.tab.h"
%}
%%
"constraint"                  return tCONSTRAINT;
"domain"                      return tDOMAIN;
"problem"                     return tPROBLEM;
"variable"                    return tVARIABLE;
"with"                        return tWITH;
"=="                          return tEQ;
"<="                          return tLE;
">="                          return tGE;
[_[:alpha:]][_[:alnum:]]*     yylval.s = new std::string(yytext);  return tIDENTIFIER;
[[:digit:]]+                  yylval.i = std::stoi(yytext); return tINTEGER; /*overlow catch*/
[-+*/%^(){};><]               return *yytext;
[\n\t ]                       ;
.                             ; /* ignore all the rest except \n*/
%%

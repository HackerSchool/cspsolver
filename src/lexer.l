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
"true"                        return tTRUE;
"false"                       return tFALSE;
"range"                       return tRANGE;
"for"                         return tFOR;
"in"                          return tIN;
"=="                          return tEQ;
"<="                          return tLE;
">="                          return tGE;
"!="                          return tNE;
[_[:alpha:]][_[:alnum:]]*     yylval.s = new std::string(yytext);  return tIDENTIFIER;
[[:digit:]]+                  yylval.i = std::stoi(yytext); return tINTEGER; /*overlow catch*/
[-+*/%^(){};><,|]              return *yytext;
[\n\t ]                       ;
.                             ; /* ignore all the rest except \n*/
%%

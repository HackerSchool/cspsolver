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
[_[:alpha:]][_[:alnum:]]*     yylval.s = new std::string(yytext);  return tIDENTIFIER;
[[:digit:]]+                  yylval.i = strtol(yytext, NULL, 10); return tINTEGER;
[-+*/%=^()]                   return *yytext;
.                          ; /* ignore all the rest */
%%

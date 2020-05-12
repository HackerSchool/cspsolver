#include "problem.h"

extern int yyparse(Problem* problem);

#ifndef TEST
int main () {
    Problem problem;
    yyparse(&problem);
    int i = 3;
}
#endif

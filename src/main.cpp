#include "problem.h"

extern int yyparse(Problem* problem);

int main () {
    Problem problem;
    yyparse(&problem);
    int i = 3;
}

#include "problem.h"
#include <iostream>
extern int yyparse(Problem** problem);

#ifndef TEST
int main () {
    Problem* problem;
    yyparse(&problem);

    try {
        problem->check();
        problem->solve();
    } catch (std::string s) {
        std::cerr << "Error: " << s << std::endl;
    } catch (const char* s) {
        std::cerr << "Error: " << s << std::endl;
    }
}
#endif

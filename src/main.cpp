#include "problem.h"
#include <iostream>
extern int yyparse(Problem** problem);



#ifndef TEST
int main () {
    Problem* problem; 

    std::cout << "Parsing...\n";
    int parse = yyparse(&problem);

    switch (parse) {
        case 1:
            std::cout << "Syntax Errors!\nExiting.";
            return 1;
            break;
        case 2:
            std::cout << "Memory out!\nExiting.";
            return 1;
            break;
    }

    try {
        std::cout << "Checking...\n";
        problem->check();
        std::cout << "Solving...\n";
        problem->solve();
    } catch (std::string s) {
        std::cerr << "Error: " << s << std::endl;
    } catch (const char* s) {
        std::cerr << "Error: " << s << std::endl;
    }

    return 0;
}
#endif

SRC_CPP = $(wildcard *.cpp)
OFILES  = $(SRC_CPP:%.cpp=%.o)

all: lex.yy.c y.tab.c y.tab.h $(OFILES)
	g++ *.cpp *.c -o cspsolver

lex.yy.c: lexer.l
	flex lexer.l
	
y.tab.c y.tab.h: parser.y
	byacc -dtv parser.y
	
%.o: %.cpp
	g++ -c $< -o $@
	
%.tab.o:: %.tab.c
	g++ -DYYDEBUG -c $< -o $@
	
clean: 
	rm *.o *.output *tab* *yy* cspsolver

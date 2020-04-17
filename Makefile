SRC_FILES = $(wildcard src/*.cpp)
OBJ_FILES = $(SRC_FILES:%.cpp=%.o) lex.yy.o y.tab.o
LIB_FLAGS = -Isrc -I.

all: $(OBJ_FILES)
	g++ $(LIB_FLAGS) $(OBJ_FILES) -o cspsolver 

lex.yy.c: src/lexer.l
	flex src/lexer.l
	
y.tab.c y.tab.h: src/parser.y
	byacc -dtv src/parser.y
	
src/%.o: src/%.cpp
	g++ $(LIB_FLAGS) -c $< -o $@
	
y.tab.o: y.tab.c 
	g++ $(LIB_FLAGS) y.tab.c -DYYDEBUG -c

lex.yy.o: lex.yy.c y.tab.h 
	g++ $(LIB_FLAGS) lex.yy.c -c -o $@ 	
	
clean: 
	rm -f src/*.o *.o *.output *tab* *yy* cspsolver

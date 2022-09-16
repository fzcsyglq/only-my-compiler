g++ main.cpp visitor.cpp SysYLexer.cpp SysYParser.cpp ../ir/ir.cpp ../backend/asm.cpp -o compiler -lantlr4-runtime
./compiler -S -o testcase.s testcase.sy
arm-linux-gnueabihf-as -g -o main.o testcase.s && arm-linux-gnueabihf-gcc -g -o main main.o

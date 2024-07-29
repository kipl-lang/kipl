cmake_minimum_required(VERSION 3.28)
project(interpreter C)

set(CMAKE_C_STANDARD 11)

add_executable(interpreter src/main.c
        src/token/token.c
        src/token/token.h
        src/lexer/lexer.c
        src/lexer/lexer.h
        src/parser/parser.c
        src/parser/parser.h
        src/parser/global.h
        src/parser/Scope/scope.c
        src/parser/Scope/scope.h
        src/parser/variables/variable.c
        src/parser/variables/variable.h
)

/**
 The Kipl Programming Language

 File: main.c

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer/lexer.h"
#include "parser/parser.h"

int main(int argc, const char* argv[]) {
    setlocale(LC_ALL, "en_US.UTF-8");

    if(argc != 2) { // Check if the user has provided a filename
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1]; // Get the filename
    size_t len = strlen(filename); // Get the length of the filename

    if(len < 6 || strcmp(filename + len - 5, ".kipl") != 0) { // Check if the file has a .kipl extension
        printf("File must have a .kipl extension\n");
        return 1;
    }

    FILE* file = fopen(filename, "r"); // Open the file
    if(file == NULL) { // Check if the file could not be opened
        printf("Could not open file %s\n", filename);
        return 1;
    }

    fseek(file, 0, SEEK_END); // Seek to the end of the file
    long fileSize = ftell(file); // Get the file size
    fseek(file, 0, SEEK_SET); // Seek back to the beginning of the file

    // Allocate memory for the file content
    char* source = (char*)malloc(fileSize + 1); // +1 for null terminator
    if(source == NULL) {
        // Check if memory allocation failed
        printf("Memory allocation failed\n");
        fclose(file);
        return 1;
    }

    // Read the file content into the source buffer
    size_t readSize = fread(source, 1, fileSize, file);
    source[readSize] = '\0'; // Null-terminate the string

    fclose(file);  // Close the file

    char* string = source;
    Token* token =  scanner(string);
    parser(token);

    //system("pause");
    freeTokens(token); // free memory

    return 0;
}

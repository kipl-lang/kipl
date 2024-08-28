//
// Created by Kerem on 28/08/2024.
//

#include "readFile.h"
#include "../../error/error.h"
#include <stdio.h>
#include <stdlib.h>

char* readFile(const char* filePath) {
    FILE* file = fopen(filePath, "r"); // Open the file
    if(file == NULL) { // Check if the file could not be opened
        char errMsg[128];
        sprintf(errMsg, "Could not open file %s\n", filePath);
        showError(ERROR_RUNTIME, errMsg);
    }

    fseek(file, 0, SEEK_END); // Seek to the end of the file
    long fileSize = ftell(file); // Get the file size
    fseek(file, 0, SEEK_SET); // Seek back to the beginning of the file

    // Allocate memory for the file content
    char* source = (char*)malloc(fileSize + 1); // +1 for null terminator
    if(source == NULL) {
        // Check if memory allocation failed
        fclose(file);
        showError(ERROR_RUNTIME, "Memory allocation failed\n");
    }

    // Read the file content into the source buffer
    size_t readSize = fread(source, 1, fileSize, file);
    if(source != NULL)
        source[readSize] = '\0'; // Null-terminate the string

    fclose(file);  // Close the file

    return source;
}

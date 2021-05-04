/**
 * Abstraction for reading in file contents.
 */
#ifndef AX_FILEIO_H
#define AX_FILEIO_H

#include "Types.h"


/**
 * Get the size of the file from a supplied file handle.
 *
 * @param FILE* file stream.
 *
 * @return int
 */
static int GetFileSizeFH(FILE* stream)
{
    fseek(stream, 0, SEEK_END);
    int size = ftell(stream);
    fseek(stream, 0, SEEK_SET);

    return size;
}

/**
 * Get the size of the file.
 *
 * @param FILE* file stream.
 *
 * @return int
 */
static int GetFileSize(const char* filename)
{
    FILE* fh = fopen(filename, "r");
    fseek(fh, 0, SEEK_END);
    int size = ftell(fh);
    fseek(fh, 0, SEEK_SET);
    fclose(fh);

    return size;
}

/**
 * Read the contents of a file into a string. Allocates
 * memory, so must be freed.
 *
 * @param const char* filename
 * @param char* buffer
 *
 * @return char*
 */
void ReadFile(const char* filename, char* buffer)
{
    FILE* fh = fopen(filename, "r");
    const int bufferSize = GetFileSizeFH(fh) + 1;
    char data[bufferSize];
    buffer = malloc(sizeof(char) * bufferSize);

    char c;
    int i = 0;
    while( (c = fgetc(fh)) != EOF )
    {
        /* TODO: Implement buffer read.  <02-05-21, Me> */
    }

    fclose(fh);
}

#endif
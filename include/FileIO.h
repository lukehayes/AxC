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
static int GetFileSizeFH(FILE* stream);

/**
 * Get the size of the file.
 *
 * @param FILE* file stream.
 *
 * @return int
 */
static int GetFileSize(const char* filename);

/**
 * Read the contents of a file into a string. Allocates
 * memory, so must be freed.
 *
 * @param const char* filename
 * @param char** buffer
 *
 * @return char*
 */
void ReadFile(const char* filename, char** buffer);

#endif

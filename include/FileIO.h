/**
 * Abstraction for reading in file contents.
 */
#ifndef AX_FILEIO_H
#define AX_FILEIO_H

/**
 * Get the size of the file.
 *
 * @param FILE* file stream.
 *
 * @return int
 */
static int GetFileSize(FILE* stream)
{
    fseek(stream, 0, SEEK_END);
    int size = ftell(stream);
    fseek(stream, 0, SEEK_SET);

    return size;
}

/**
 * Read the contents of a file into a string. Allocates
 * memory, so must be freed.
 *
 * @param const char* path
 * @param char* buffer
 *
 * @return char*
 */
char* ReadFile(const char* path, char* buffer)
{
    FILE* fh = fopen(path, "r");
    const int bufferSize = GetFileSize(fh);

    buffer = malloc(sizeof(char) * bufferSize);

    for(int i = 0; i<= bufferSize; i++)
    {
        buffer[i] = fgetc(fh);
    }


    fclose(fh);

    return buffer;
}

#endif

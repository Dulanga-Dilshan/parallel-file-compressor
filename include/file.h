#ifndef FILE_H
#define FILE_H
#include<stdio.h>
#include<stddef.h>

#define CHUNK_SIZE 104857600
 
    typedef struct file_t{
        unsigned char* fdata;
        unsigned int size;
    }file_t;

    typedef struct file_info{
        FILE* file;
        unsigned long byte_count;
    }file_info;


    file_t* read_file(const char* filename);
    unsigned int file_size(FILE* file);
    void close_file(file_t* file);
    void print_bytes(file_t* file,__uint32_t length);
    void count_bytes(file_t* file,unsigned long arr[],__uint32_t length); 
    file_t* read_chunk(FILE* file);



#endif //FILE_H
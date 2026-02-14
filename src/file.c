#include "file.h"
#include<stdlib.h>


file_t* read_file(const char* filename){
    FILE* file_h=fopen(filename,"rb");
    if(!file_h){
        perror(filename);
        exit(EXIT_FAILURE);
    }

    file_t* file=(file_t*)malloc(sizeof(file_t));
    if(!file){
        perror("maloc faild!\n");
        fclose(file_h);
        exit(EXIT_FAILURE);
    }

    file->size=file_size(file_h);
    size_t file_size=file->size;

    file->fdata=(unsigned char *)malloc((sizeof(char)*file->size)+1);

    
    fread(file->fdata,1,file->size,file_h);
    file->fdata[file->size]='\0';
    fclose(file_h);
    return file;
}

unsigned int file_size(FILE* file){
    if(!file) return 0;
    unsigned int size;
    fseek(file,0,SEEK_END);
    size=ftell(file);
    rewind(file);
    return size;
}

void close_file(file_t* file){
    free(file->fdata);
    free(file);
    file=NULL;
}

void print_bytes(file_t* file,__uint32_t length){
    if(length==0){
        length=file->size;
    }
    for(unsigned int i=0;i<length;i++){
        printf("%02X %03u  ",file->fdata[i],(unsigned int)file->fdata[i]);
        if((i+1)%15==0){
            printf("\n");
        }
    }
    printf("\n");
}

void count_bytes(file_t* file,unsigned long arr[],__uint32_t length){
    if(length==0){
        length=file->size;
    }
    for(unsigned int i=0;i<length;i++){
        arr[(unsigned int)file->fdata[i]]+=1;
    }
}


file_t* read_chunk(FILE* file){
    file_t* chunk=(file_t*)malloc(sizeof(file_t));
    if(!file){
        perror("malloc faild!");
        exit(EXIT_FAILURE);
    }
    chunk->fdata=(unsigned char*)malloc(CHUNK_SIZE);
    if(!chunk->fdata){
        free(file);
        perror("malloc faild!");
        exit(EXIT_FAILURE);
    }

    chunk->size=fread(chunk->fdata,1,CHUNK_SIZE,file);

    return chunk;

}

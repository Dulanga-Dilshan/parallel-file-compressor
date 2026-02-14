#include "thread.h"
#include<stdlib.h>

void add_result(unsigned long byte_count[],unsigned long result[]){
    for(size_t i=0;i<265;i++){
        byte_count[i]+=result[i];
    }
}

int process_chunks(file_info* file){
    unsigned long byte_count[256];
    pthread_mutex_lock(&file_mutex);
    file_t* chunk=read_chunk(file->file);
    pthread_mutex_unlock(&file_mutex);
    if(chunk->size==0){
        return 0;
    }
    count_bytes(chunk,byte_count,0);

    pthread_mutex_lock(&file_mutex);
    add_result(file->byte_count,byte_count);
    pthread_mutex_unlock(&file_mutex);
    
    free(chunk->fdata);
    free(chunk);

    return 1;

}


void* execute_treads(void* data){
    int i=0;
    
    while(process_chunks((file_info*)data)){
        printf("treads: %d\n",i++);
    }
}


void process_file(const char* filepath,unsigned long byte_count[]){
    file_info file;
    file.file=fopen(filepath,"rb");
    file.byte_count=byte_count;
    if(!file.file){
        perror(filepath);
        exit(EXIT_FAILURE);
    }
    pthread_mutex_init(&file_mutex,NULL);
    




}
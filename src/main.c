#include<stdio.h>
#include "file.h"
#include "encoder.h"
#include<stdlib.h>  
#include "thread.h"
   
int main(void){
    unsigned long byte_count[256]={0};
    file_t* file=read_file("src/data.txt");

    print_bytes(file,0);
    count_bytes(file,byte_count,0); 
    close_file(file);
 /*

  

    priority_queue* byte_queue=initpriorityqueue();
    binary_tree* binary_tree=binary_tree_init();

    insert_bytes(byte_queue,byte_count);

    unsigned long fullcount=0;

    for(int i=0;i<256;i++){
        printf("%03d - % 7d  ",i,byte_count[i]);
        fullcount+=byte_count[i];
        if((i+1)%8==0){
            printf("\n");
        }
    }
    printf("%ld\n",fullcount);

    unsigned int min=byte_count[0],max=byte_count[0];
    unsigned int minindex=0,maxindex=0;

    for(int i=1;i<256;i++){
        if(min>byte_count[i]){
            min=byte_count[i];
            minindex=i;
        }
        if(max<byte_count[i]){
            max=byte_count[i];
            maxindex=i;  
        }
    }

    printf("max:%d - %u\nmin=%d - %u\n",maxindex,max,minindex,min);

    node* n;
    for(;!isempty(byte_queue);){
        n=dequeue(byte_queue);
        printf("byte: %02x count %05u\n",n->data.byte,n->data.count);
        free(n);
    }






    build_huffmen_tree(binary_tree,byte_queue);

    printf("root node waight:%lu\n",binary_tree->root_node->data.count);

    


    treedepth(binary_tree);

    assignCodes(binary_tree);
    print_tree(binary_tree);
    binary_tree_destroy(binary_tree);
    priority_queue_destroy(byte_queue);

*/ 
  
    return 0;
}
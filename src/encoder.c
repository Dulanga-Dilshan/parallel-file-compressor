#include "encoder.h"
#include<stdlib.h>
#include<string.h>

priority_queue* initpriorityqueue(){
    priority_queue* queue=(priority_queue*)malloc(sizeof(priority_queue));
    queue->top=-1;
    queue->size=0;
    return queue;
}

void enqueue(priority_queue* queue,unsigned char byte,long count){
    if(queue->top >= QUEUE_SIZE){
        perror("queue is full");
        exit(EXIT_FAILURE);
    }
    if(count==0) return;
    queue->top++;
    queue->array[queue->top]=(node* )malloc(sizeof(node));
    queue->array[queue->top]->data.byte=byte;
    queue->array[queue->top]->data.count=count;
    queue->array[queue->top]->left=NULL;
    queue->array[queue->top]->right=NULL;

    node* temp;

    for(size_t i=queue->top; i>0 && queue->array[i]->data.count < queue->array[i-1]->data.count;i--){
        temp=queue->array[i];
        queue->array[i]=queue->array[i-1];
        queue->array[i-1]=temp;
    }

    queue->size++;
}

void enqueue_node(priority_queue* queue,node* data){
    if(queue->top >= QUEUE_SIZE){
        perror("queue is full");
        exit(EXIT_FAILURE);
    }
    queue->top++;
    queue->size++;
    queue->array[queue->top]=data;

    node* temp;
    for(size_t i=queue->top; i>0 && queue->array[i]->data.count < queue->array[i-1]->data.count;i--){
        temp=queue->array[i];
        queue->array[i]=queue->array[i-1];
        queue->array[i-1]=temp;
    }
    //printf("dequeue node. size%d\n",queue->size);
}

bool isempty(priority_queue* queue){
    if(!queue){
        perror("null pointer");
        exit(EXIT_FAILURE);
    }
    if(queue->top==-1) return true;
    return false;
}


node* dequeue(priority_queue* queue){
    if(isempty(queue)){
        perror("empty queue (dequeue)");
        exit(EXIT_FAILURE);
    }
    node* temp=queue->array[0];

    for(size_t i=1;i<=queue->top;i++){
        queue->array[i-1]=queue->array[i];
    }
    queue->top--;
    queue->size--;
    
    return temp;
}

/*Inserts elements to the priority queue*/
void insert_bytes(priority_queue* queue,unsigned long byte_arr[]){
    for(size_t i=0;i<256;i++){
        enqueue(queue,(unsigned char)i,byte_arr[i]);
    }
}

void priority_queue_destroy(priority_queue* queue){
    queue->top=-1;
    free(queue);
    queue=NULL;
}

void print_queue(priority_queue* queue){
    for(size_t i=0;i<=queue->top;i++){
        printf("byte: %02x count: %lu\n",queue->array[i]->data.byte, queue->array[i]->data.count);
    }
}



binary_tree* binary_tree_init(){
    binary_tree* tree=(binary_tree*)malloc(sizeof(binary_tree));
    tree->root_node=NULL;
    tree->temp_node=NULL;
    tree->depth=0;
    return tree;
}


void _binary_tree_destroy(node* temp){
    if(temp==NULL) return;
    _binary_tree_destroy(temp->left);
    _binary_tree_destroy(temp->right);
    free(temp->data.huffmen_code);
    temp->data.huffmen_code=NULL;
    free(temp);
    temp=NULL;

}

void binary_tree_destroy(binary_tree* tree){
    _binary_tree_destroy(tree->root_node);
    tree->root_node=NULL;
    tree->temp_node=NULL;
    free(tree);
    
}

void build_huffmen_tree(binary_tree* tree,priority_queue* queue){
    node* temp;
    while(queue->size>1){
        temp=(node* )malloc(sizeof(node));
        temp->left=dequeue(queue);
        temp->right=dequeue(queue);
        temp->data.count=temp->left->data.count+temp->right->data.count;
        temp->data.huffmen_code=NULL;
        temp->data.code_length=0;
        enqueue_node(queue,temp);
    }

    tree->root_node=dequeue(queue);
    tree->temp_node=NULL;
}

void _print_tree(node* temp){
    if(temp==NULL) return;
    _print_tree(temp->right);
    _print_tree(temp->left);
    if(temp->left==NULL && temp->right==NULL){
        printf("byte: %02x count: %05lu bytecode:% 15s length:%d \n",temp->data.byte,temp->data.count,temp->data.huffmen_code,temp->data.code_length);
    }
    
}

void print_tree(binary_tree* tree){
    _print_tree(tree->root_node);
}

int _depth(node* temp){
    if(!temp) return -1;
    int l=_depth(temp->left);
    int r=_depth(temp->right);
    return ((l < r) ? r : l)+1;
}

void treedepth(binary_tree* tree){
    if(!tree) return;
    tree->depth=_depth(tree->root_node);
}

void _assignCodes(node* tmp,char* buff,int depth,int max_depth){
    if(!tmp) return;
    if(depth>max_depth){
        perror("depth");
        exit(EXIT_FAILURE);
    }
    if(tmp->left==NULL && tmp->right==NULL){
        tmp->data.huffmen_code=(unsigned char* )malloc((sizeof(char)*depth)+1);
        memcpy(tmp->data.huffmen_code,buff,sizeof(char)*depth);
        tmp->data.huffmen_code[depth]='\0';
        tmp->data.code_length=depth;
    }

    buff[depth]='1';
    _assignCodes(tmp->left,buff,depth+1,max_depth);
    buff[depth]='0';
    _assignCodes(tmp->right,buff,depth+1,max_depth);
}

void assignCodes(binary_tree* tree){
    char* buff=malloc((sizeof(char)*tree->depth)+1);
    _assignCodes(tree->root_node,buff,0,tree->depth);
    free(buff);
}
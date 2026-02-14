#ifndef ENCODER_H
#define ENCODER_H 
 
#include<stdio.h>
#include<stddef.h>
#include<stdbool.h>

#define QUEUE_SIZE 256

    typedef struct byte_info{
        unsigned char byte;
        unsigned long count;
        unsigned char* huffmen_code;
        unsigned int code_length;
    }byte_info;

    typedef struct node{
        byte_info data;
        struct node* left;
        struct node* right;
    }node;

    typedef struct priority_queue{
        node* array[QUEUE_SIZE];
        int top;
        int size;
    }priority_queue;

    typedef struct binary_tree{
        unsigned int depth;
        node* root_node;
        node* temp_node;
    }binary_tree;
    
    priority_queue* initpriorityqueue();
    void insert_bytes(priority_queue* queue,unsigned long byte_arr[]);
    void priority_queue_destroy(priority_queue* queue);
    void print_queue(priority_queue* queue);
    void build_huffmen_tree(binary_tree* tree,priority_queue* queue);
    binary_tree* binary_tree_init();
    void print_tree(binary_tree* tree);
    node* dequeue(priority_queue* queue);
    bool isempty(priority_queue* queue);
    void binary_tree_destroy(binary_tree* tree);
    void treedepth(binary_tree* tree);
    void assignCodes(binary_tree* tree);


#endif //ENCODER_H
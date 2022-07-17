#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char key;
typedef int value;
#define null_key 0
#define null_value -1

typedef struct bst_t {
    key k;
    value v;
    int size;
    struct bst_t* l;
    struct bst_t* r;
} bst;

value st_get(bst* t, key k);
void st_put(bst* t, key k, value v);
key st_floot(bst* t, key k);

#endif
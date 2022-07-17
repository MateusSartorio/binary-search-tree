#include "../h/bst.h"

int compare(key k1, key k2) {
    return k1 - k2;
}

static int size(bst* t) {
    if(!t)
        return 0;
    return t->size;
}

static bst* create_node(key k, value v) {
    bst* t = (bst*) malloc(sizeof(bst));
    
    t->k = k;
    t->v = v;
    t->l = NULL;
    t->r = NULL;

    return t;
}

static value rec_get(bst* t, key k) {
    if(!t)
        return null_value;
    
    int cmp = compare(k, t->k);
    if(cmp < 0)
        return rec_get(t->l, k);
    else if(cmp > 0)
        return rec_get(t->r, k);
    else
        return t->v;
}

// vue st_get(bst* t, key k) {
//     return rec_get(t, k);
// }

value st_get(bst* t, key k) {
    bst* n = t;

    int cmp = 0;
    while(n) {
        cmp = compare(k, n->k);
        if(cmp < 0)
            n = n->l;
        else if(cmp > 0)
            n = n->r;
        else
            return n->v;
    }

    return null_value;
}

static bst* rec_put(bst* t, key k, value v) {
    if(!t)
        return create_node(k, v);
    
    int cmp = compare(k, t->k);
    if(cmp < 0)
        t->l = rec_put(t->l, k, v);
    else if(cmp > 0)
        t->r = rec_put(t->r, k, v);
    else
        t->v = v;
    
    t->size = size(t->l) + size(t->r) + 1;
    return t;
}

// void st_put(bst* t, key k, value v) {
//     rec_put(t, k, v);
// }

void st_put(bst* t, key k, value v) {
    if(!t) {
        t = create_node(k, v);
        return;
    }

    bst* n = t;
    bst* parent = NULL;
    int cmp = 0;
    while(n) {
        parent = n;
        cmp = compare(k, n->k);
        if(cmp < 0)
            n = n->l;
        else if(cmp > 0)
            n = n->r;
        else {
            n->v = v;
            return;
        }
    }

    //There is a part missing in here
}

static bst* rec_floor(bst* t, key k) {
    if(!t)
        return NULL;
    
    int cmp = compare(k, t->k);
    if(cmp == 0)
        return t;
    if(cmp < 0)
        return rec_floor(t->l, k);
    
    bst* n = rec_floor(t->r, k);
    if(n)
        return n;
    
    return t;   
}

key st_floot(bst* t, key k) {
    bst* n = rec_floor(t, k);
    if(!n)
        return null_key;
    return n->k;
}

//Como exercicio implementar o st_ceiling()

static int rec_rank(bst* t, key k) {
    if(!t)
        return 0;
    
    int cmp = compare(k, t->k);
    if(cmp < 0)
        return rec_rank(t->l, k);
    if(cmp > 0)
        return size(t->l) + rec_rank(t->r, k) + 1;
    else
        return size(t->l);

}

int st_rank(bst* t, key k) {
    return rec_rank(t, k);
}

static void rec_traverse(bst* t, void (*visit)(key, value)) {
    if(!t)
        return;
    rec_traverse(t->l, visit);
    visit(t->k, t->v);
    rec_traverse(t->r, visit);
}

void st_traverse(bst* t, void (*visit)(key, value)) {
    rec_traverse(t, visit);
}

// static bst* del_min(bst* t, bool del) {

// }

static bst* rec_delete(bst* t, key k) {
    if(!t)
        return NULL;
    
    int cmp = compare(k, t->k);
    if(cmp < 0)
        t->l = rec_delete(t->l, k);
    else if(cmp > 0)
        t->r = rec_delete(t->r, k);
    else {
        if(!t->r) {
            
        }
    }
}

void st_delete(bst* t, key k) {
    rec_delete(t, k);
}
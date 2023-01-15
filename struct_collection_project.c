#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node *element(struct node *dll, int i) ;
struct node *add(struct node *dll, int i, int value) ;
struct node *delete(struct node *dll, int i);

struct node {
    int value;
    struct node *next;
    struct node *prev;
};

void printNode (struct node *dll) {
    if (dll != NULL) {
        printf("< This: %p - %d - P : %p - N : %p >\n", dll, dll->value, dll->prev, dll->next);
    } else {
        printf("Null Pointer");
    }
} 


void printLL (struct node *dll) {
    struct node* ptr = dll;
    printf("---\n");
    while (ptr != NULL) {
        printNode(ptr);
        ptr = ptr->next;
    }
    printf("---\n\n");
} 

int main () {
    struct node *dll = malloc(sizeof(struct node));
    dll->value = 1;
    dll->next = NULL; 
    dll->prev = NULL; 
    printLL(dll);
    dll = add(dll, -1, 3);
    printLL(dll);
    dll = add(dll, -1, 4);
    printLL(dll);
    dll = add(dll, 1, 2);
    printLL(dll);
    dll = add(dll, 2, 7);
    printLL(dll);
    dll = add(dll, 9, -1);
    printLL(dll);
    dll = delete(dll, 2);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 4);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll); 
    dll = delete(dll, 0);
    printLL(dll); 
    dll = delete(dll, 0);
    printLL(dll); 
    dll = delete(dll, 0);
    printLL(dll); 
}

/* Expected Output: 

---
< This: 0x1cf8590 - 1 - P : (nil) - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf8610 >
< This: 0x1cf8610 - 7 - P : 0x1cf85f0 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8610 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

*/ 


struct node *element(struct node *dll, int i){
    struct node *current = dll;
    int counter = 0;
    while (current != NULL){
        if (counter == i){
            return current;
        }
        counter++;
        current = current->next;
    }
    return NULL;
}

struct node *delete(struct node *dll, int i){
    struct node *copy = dll;
    int sizecpy = 0;
    while (copy != NULL){
        sizecpy++;
        copy = copy->next;
    }
    
    struct node *cur = element(dll,i);
    struct node *previous = element(dll,i-1);

    if (i == 0){
        if (sizecpy == 1){
            return NULL;
        }
        else{
            cur->next->prev=NULL;
            return cur->next;
        }
    }
    else{
        if (cur == NULL){
            return dll;
        }
        else if (cur->next == NULL){
            previous->next = NULL;
        }
        else{
            previous->next = cur->next;
            cur->next->prev = previous;
        }
        return dll;
    }
}
struct node *add(struct node *dll, int i, int value){
    struct node *temp = dll;
    int counter = 0;

    while( temp != NULL) {
        counter++;
        temp = temp->next;
    }
    
    if (i < 0){
        struct node *cur = dll;
        while (cur->next != NULL){
            cur = cur->next;
        }
        cur->next = malloc(sizeof(struct node));
        cur->next->value = value;
        cur->next->next = NULL;
        cur->next->prev = cur;
        return dll;
    }
    else if (i >= counter){
        struct node *cur = dll;
        while (cur->next != NULL){
            cur = cur->next;
        }
        cur->next = malloc(sizeof(struct node));
        cur->next->value = value;
        cur->next->next = NULL;
        cur->next->prev = cur;
        return dll;
    }
    else if (i == 0){
        struct node* mybad = malloc(sizeof(struct node));
        mybad->value = value;
        mybad->next = temp;
        mybad->prev = NULL;
        temp->prev = mybad;
        return mybad;
        } 
    else{
        struct node *cur = element(dll,i);
        struct node *previous = element(dll,i-1);
        previous->next= malloc(sizeof(struct node));
        previous->next->next = cur;
        previous->next->value = value;
        previous->next->prev = previous;
        cur->prev = previous ->next;
        return dll;
    }
} 


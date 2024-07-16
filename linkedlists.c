#include <stdio.h>
#include <stdlib.h>

// arrays store values in continuos form so any modification is very hard
// linked lists are not continuous and each node only knows where the next node is (different memory addresses)
// NULL is the address for the last one (tail)

// no shifting is required, we insert or delete(make the node point to node after the one being deleted)

struct node {
    int value;
    struct node *next; // struct pointer pointing to next element 
};

void printall(struct node* list){
    struct node* p = list;
    while(p!=NULL){
        printf("%d\n", p->value);
        p = p->next;
    }
}

void clear(struct node* list) // since we are allocating memory we need to free it
{
    struct node* p = list;
    while(p != NULL){
        struct node* temp = p; // temporary node holding list
        p = p->next; // traversing through list
        free(temp); // freeing the list
    }

}

struct node* add_to_end(struct node* list, int value)
// we need to find node before tail (pointing to null), make that node point to new node (being added) and new node to tail (NULL)
{
    struct node* new = malloc(sizeof(struct node));
    new->next = NULL; // new node pointing to NULL (tail)
    new->value = value;
    if(list == NULL){
        return new; // if list is empty new becomes our list
    }
    struct node* p = list;
    // p->next is pointer p pointing to another struct pointer next 
    while(p->next != NULL){
        p = p->next; // finding node before tail (second last)
    }
    // p->next now points to null here so we make it point to new node baing added at end
    p->next = new; // p->next(last) points to new and new->next points to null (tail - becomes last)
    // order becomes p new new->next (last- NULL)
    return list;
}

int main(){
    struct node* list = NULL;

    list = add_to_end(list, 1);
    list = add_to_end(list, 3);
    list = add_to_end(list, 5);

    printall(list);
    clear(list);

    return 0;
}
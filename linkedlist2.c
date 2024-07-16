#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* next;
};

struct node* insert(struct node* list, int value){
    struct node* new = malloc(sizeof(struct node));
    new->value = value;
    new->next = NULL;

    //if list is empty
    if(list == NULL){
        return new;
    }

    struct node* current = list;
    struct node* previous = NULL;

// going through list to see if value should be added to beginning, (somewhere in the) middle or end
    while(current != NULL && current->value != value){
        previous = current;
        current = current->next;
    }

// repointing the next pointer of new node - now new next always points to current
    new->next = current;

// being added to beginning
    if(previous == NULL){
        return new;
        // making a new list where new element is at beginning and the whole previous list is copied(appended to new)
        // since new->next is already appointed to current hence older list auto gets appended to new 
    }

// somewhere in the middle - none of them equal to NULL (this will also be used to add to end)
    previous->next = new;
    new->next = current;
    return list;

}

void printall(struct node* list){
    struct node* p = list;
    while(p != NULL){
        printf("%d\t", p->value);
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

struct node* delete(struct node* list, int value){
    struct node* current = list;
    struct node* previous = NULL;

// going through list to see position of value being deleted
    while(current != NULL && current->value <= value){
        previous = current;
        current = current->next;
    }
    if(current == NULL) return list;
    // if current is NULL that means the whole list has been traveresed and there was no match hence nothing to delete
    
    if(previous == NULL){
        list = list->next;
        free(current); // getting rid of the current pointer (which is pointing to the list)
        // since previous points to null it is not associated to list hence does not need to be freed
        return list;
    }

    // previous and current both not NULL
    previous->next = current->next;
    free(current);
    return list;

}

int main(){
    struct node *list;

    list = insert(list, 3);

    list = insert(list, 1);
    list = insert(list, 5);
    list = insert(list, 4);
    printall(list);


    list = delete(list, 4);
    printf("\nafter deletion\n");
    printall(list);

    clear(list);
    
    return 0;
}
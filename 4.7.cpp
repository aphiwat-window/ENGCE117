#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
    char name[20];
    int age;
    float gpa;
    struct studentNode *next;
};

void saveNode(struct studentNode *child, const char n[], int a, float g);
void GoNext(struct studentNode **now);

int main() {
    struct studentNode *start, *now;
    start = (struct studentNode * )malloc( sizeof( struct studentNode ) ) ;
    saveNode(start, "Alice", 20, 3.5);

    start->next = (struct studentNode * )malloc( sizeof( struct studentNode ) ) ;
    saveNode(start->next, "Bob", 22, 3.8);

    start->next->next = (struct studentNode * )malloc( sizeof( struct studentNode ) ) ;
    saveNode(start->next->next, "Charlie", 21, 3.7);

    now = start;

    GoNext(&now);  // Move to next node and print
    GoNext(&now);  // Move to next node and print
    GoNext(&now);  // Move to next node and print

    return 0;
}

void saveNode(struct studentNode *child, const char n[], int a, float g) {
    strcpy(child->name, n);
    child->age = a;
    child->gpa = g;
    child->next = NULL;
}

void GoNext( struct studentNode **now ) {
    if ( *now != NULL ) {
        printf( "%s\n" , (*now)->name ) ;
        if ( (*now)->next != NULL) {
            *now = (*now)->next ;
        } else {
            printf( "End of List" ) ;
            *now = NULL;
        }//end if
    }//end if
}//end GoNext
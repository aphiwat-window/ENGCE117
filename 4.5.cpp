#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

void SaveNode( struct studentNode *child, char n[], int a, char s, float g ) ;
void GoNext2( struct studentNode **walk ) ;

int main() {
    char name[20] = "one";
    struct studentNode *start, *now1, **now2 ;
    start = (struct studentNode * )malloc( sizeof( struct studentNode ) ) ;
    SaveNode( start , name , 6, 'M', 3.11 ) ;

    char name2[20] = "two" ;
    start->next = (struct studentNode * )malloc( sizeof( struct studentNode ) ) ;
    SaveNode( start->next , name2, 8, 'F', 3.22 ) ;

    char name3[20] = "three" ;
    start->next->next = (struct studentNode * )malloc( sizeof( struct studentNode ) ) ;
    SaveNode( start->next->next , name3, 10 , 'M', 3.33 ) ;

    char name4[20] = "four" ;
    start->next->next->next = (struct studentNode * )malloc( sizeof( struct studentNode ) ) ;
    SaveNode( start->next->next->next , name4, 12 , 'F', 3.44 ) ;
    now1 = start ;
    now2 = &start ;

    GoNext2( now2 ) ;
    printf( "%s " , ( *now2 )->name ) ;

    return 0 ;
}//end function

void SaveNode( struct studentNode *child, char n[], int a, char s, float g ) {
    strcpy( child->name, n ) ;
    child->age = a ;
    child->sex = s ;
    child->gpa = g ;
}//end function

void GoNext2( struct studentNode **walk ) {
    if ( *walk != NULL ) {
        *walk = (*walk)->next ;
    }//end if
}//end GoNext2
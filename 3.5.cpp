#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[ 20 ] ;
    int Age ;
} ; 

struct student ( *GetStudent( int *room ) )[ 10 ] ;

int main() {
    struct student ( *children )[ 10 ] ;
    int group ;
    children = GetStudent( &group ) ;
    children = ( struct student( * )[ 10 ] )malloc( group * sizeof( struct student[ 10 ] ) ) ;

    for ( int  i = 1 ; i <= group ; i++ ) {
        printf( "Room %d:\n" , i ) ;
        for ( int  j = 1; j <= 10; j++) {
            printf( "Student %d:\n" , j ) ;
            printf( "Enter name : " ) ;
            scanf( "%s" , children[ i ][ j ].name ) ;
            printf( "Enter Age : " ) ;
            scanf( "%d" , &children[ i ][ j ].Age ) ;
        }//end for j
    }//end for i
    printf( "\n" ) ;
    for ( int i = 1 ; i <= group ; i++ ) {
        printf( "Room %d: 10 students entered.\n" , i ) ;
    }//end for print room


    /*
        for ( int  i = 1 ; i <= group ; i++) {
            printf( "Room %d:\n" , i ) ;
            for ( int  j = 1 ; j <= 10 ; j++ ) {
                printf( "Student %d : %s, %d\n" , j , children[ i ][ j ].name , children[ i ][ j ].Age ) ;
            }
            printf( "\n" ) ;
        }
    */

    return 0 ;
}//end function

struct student ( *GetStudent( int *room ) )[ 10 ] {
    printf( "Enter Room " ) ;
    scanf( "%d" , room ) ;
    return 0 ;
}//end struct student
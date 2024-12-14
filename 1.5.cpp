#include <stdio.h>
#include <stdlib.h>

void GetMatrix( int value[] , int *row, int *col ) ;
 
 int main() {
    int *data , m , n ;

    printf("Enter the number of rows: ") ;
    scanf( "%d" , &m ) ;

    printf( "Enter the number of columns: " ) ;
    scanf( "%d" , &n ) ;
    
    data = ( int * )malloc(( m ) * ( n ) * sizeof(int));

    GetMatrix( data, &m, &n ) ;
    return 0 ;

}//end function

void GetMatrix( int value[] , int *row, int *col) {
    char ch ;
    if ( *row == 0 && *col == 0 ) {
        printf( "Matrix:\n(empty)" ) ;    
    } else if ( *row == 0 && *col != 0 || *col == 0 && *row != 0 ) {
         printf( "Error: Invalid matrix dimensions." ) ;
    } else {
        printf( "Enter Enter the matrix elements: " ) ; //input
        for( int i = 0 ; i < *row ; i++ ) {
            for( int j = 0 ; j < *col ; j++ ) {
                scanf("%d" , &value [ i * ( *col ) + j ] ) ;
                ch = getchar() ; //เอาไว้เก็บ /n
                if ( ch == '\n' && j != *col - 1 ) {
                    printf( "Error: Incorrect number of elements." ) ;
                    exit( 1 ) ;
                }//end if เช็คว่ากรอกครบหรือยัง
            }//end for columns
        }//end for rows
    }//end if

    printf( "Matrix ( %d x %d )\n" , *row , *col ) ; //output
    for ( int i = 0; i < *row ; i++) {
        for ( int  j = 0; j < *col ; j++) {
            printf( "%d " , value [ i * ( *col ) + j ] ) ;
        }//end print
        printf( "\n" ) ;
    }//end for 
}// GetMatrix
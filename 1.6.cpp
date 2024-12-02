
#include <stdio.h>

int *GetMatrix( int *row, int *col ) ;

int main() {
    int *data , m , n ;
    data = GetMatrix( &m , &n ) ;
    return 0 ;
}//end function

int *GetMatrix( int *row , int *col ) {
    int arr[ 100 ][ 5 ] ;
    int count = 0 ;
    char ch ;
    printf( "Array1 element : \n" ) ; 
    scanf( "%d %d" , row , col) ;
    printf( "Input : \n" ) ;
    for( int i = 0 ; i < *row ; i++ ) {
        for( int j = 0 ; j < *col ; j++ ) {
            scanf( "%d" , &arr[ i ][ j ] ) ;
            ch = getchar() ;
            if ( ch == '\n' && j != *col - 1 ) { //เช็คว่าถ้ากรอกไม่ครบ โดยใข้ตัว \n
                printf( "Error: Invalid matrix input" ) ;
                return 0 ;
            }//end if เช็คว่ากรอกครบหรือยัง
        }//end for columns
    }//end for rows
    printf( "\n" ) ;
    if ( *row != 0 && *col != 0 ) { 
        printf( "Enter number of rows and columns: %d %d\n" , *row , *col ) ;
        printf( "Enter matrix elements:\n" ) ;
        for( int i = 0 ; i < *row ; i++ ) {
            for( int j = 0 ; j < *col ; j++ ) {
                printf( "%d " , arr[i][j] ) ;
            }//end for columns
            printf("\n") ;
        }//end for rows
    } else {
        printf( "Enter number of rows and columns: %d %d\n" , *row , *col ) ;
    }//end if ถ้ากรอก 0 0
    return 0 ;
}//end GetMatrix
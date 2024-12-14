#include <stdio.h>
#include <string.h>

/*
    #include <stdio.h>
    #include <string.h>

    void GetSet( int [], int * ) ;

    int main() {
     int *data, num ;
     GetSet( &data, &num ) ;
     return 0 ;
    }//end function
*/

void GetSet( int a[] , int *n ) ;

int main() {
    int data[ 500 ] , n = 0 ;
    GetSet( data, &n ) ;
    return 0 ;
}//end function

void GetSet( int a[] , int *n ) {
    printf( "Enter n : ") ;
    scanf( "%d" , n ) ;

    printf( "Enter data : ") ;
    for ( int i = 0 ; i < *n ; i++ ) {
        scanf( "%d" , &a[i] ) ;
    }//end for
    
    for ( int i = 0 ; i < *n ; i++ ) {
        printf( "%d " , a[ i ] ) ;
    }//end for print a
    
} //end GetSet
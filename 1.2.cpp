#include <stdio.h>
#include <string.h>

void GetSet( int [], int * ) ;

int main() {
    int data[500] , n = 0 ;
    GetSet( data, &n ) ;
    return 0 ;
}//end function

void GetSet( int a[], int *e ) {
    printf( "Enter n : ") ;
    scanf( "%d" , e ) ;

    printf( "Enter data : ") ;
    for ( int i = 0 ; i < *e ; i++ ) {
        scanf( "%d" , &a[i] ) ;
    }//end for
    
    //for (int i = 0; i < *e; i++) {
        //printf( "%d " , a[i] ) ;
    // }
    
} //end GetSet
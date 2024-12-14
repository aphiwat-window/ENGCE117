#include <stdio.h>

int isPrime( int num ) {
    int i = 2 ;
    int prime = 1 ;

    while ( i * i <= num ) {
        prime = prime * ( num % i != 0 ) ; 
        i++ ;
    }
    return prime ;
}

int main() {
    int num ;

    printf( "Enter number :\n" ) ;
    scanf( "%d" , &num ) ;

    int i = num ;
    do {
        int prime = isPrime( i ) ;
        while  ( prime ) {
            printf( "%d " , i ) ;
            prime = 0 ;
        }//end do while
        i-- ;
    } while ( i >= 2 ) ;
    printf( "\n" ) ;
    return 0 ;
}//end main

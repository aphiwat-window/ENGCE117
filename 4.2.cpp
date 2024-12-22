    #include <stdio.h>
    #include <stdlib.h>

    void go( int ***p, int **z ) ;

    int main() {
        int *b = ( int * )malloc( sizeof( int ) ) ;
        *b = 10 ;
        int *c = ( int * )malloc( sizeof( int ) ) ;
        *c = 20 ;

        
        int **a ;
        go( &a, &b ) ;
        printf( "%d %p %p %p \n", **a, *a, a, &a ) ;
        go( &a, &c ) ;
        printf( "%d %p %p %p \n", **a, *a, a, &a ) ;


        return 0 ;
    }//end function

    void go( int ***p, int **z ) {
        *p = z ; 
    }//end go
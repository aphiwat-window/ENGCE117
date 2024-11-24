#include <stdio.h>

int main() {
    float tem = 0 ;

    printf( "Enter temperature : " ) ;
    scanf( "%f" , &tem ) ;

    printf( "%.0f degree Celsius = %.1f  degree Fahrenheit" , tem , tem * 1.8 + 32 ) ;
    return 0 ;
}//end main

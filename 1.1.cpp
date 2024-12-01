/*
    จงเขียนโปรแกรมแสดงคำว่า Hello World จำนวน n บรรทัด (โดย n คือตัวเลขที่รับมาจากผู้ใช้)

    [1] Hello world
    [2] Hello world
    [3] Hello world
    [4] Hello world
    [5] Hello world
*/

#include <stdio.h>

int main() {

    int input = 0 ;

    printf( "Enter start : " ) ;    
    if ( scanf( "%d" , &input ) != 1 ) {
        printf( "please enter number only." ) ;
    } else {
        for ( int i = 1 ; i <= input ; i++ ) {
            printf( "[%d] Hello world \n" , i ) ;
        }//end for วนรอบ
    }//end if 
    printf( "Output:\n" ) ;
  
    return 0 ;
}//end main

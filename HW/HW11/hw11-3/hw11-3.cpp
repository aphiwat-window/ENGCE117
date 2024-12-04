/*
    ผู้ใช้พิมพ์ข้อความเข้ามาในระบบ และให้คุณทำการแสดงการกลับตัวอักษรทั้งหมดที่ผู้ใช้กรอกมา เช่น ผู้ใช้กรอกมาว่า Hello World คุณจะต้องแสดงบนหน้าจอว่า dlroW olleH

    Test case:
        Hello world
    Output:
        dlrow olleH

    Test case:
        RMUTL
    Output:
        LTUMR

    Test case:
        Orio
    Output:
        oirO

*/

#include <stdio.h>
#include <string.h>

void PRINT ( char n[] , char n2[] ) ;

int main () {
    char name1[ 100 ] , name2[ 100 ] ;
    printf( "Enter : " ) ;
    fgets( name1 , sizeof(name1) , stdin ) ;
    name1[ strcspn( name1 , "\n" ) ] = '\0' ;
    PRINT( name1 , name2 ) ;
    return 0 ;
}//end main

void PRINT ( char n[] , char n2[] ) {
    int len = strlen( n ) ;
    printf( "Output : " ) ;
    for ( int i = 0 ; i < len ; i++ ) {
        n2[ i ] = n[ len - 1 - i ] ; 
        printf( "%c" , n2[ i ] ) ;
    }//end for 
}//end PRINT

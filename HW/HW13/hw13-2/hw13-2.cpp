/*
    ผู้ใช้พิมพ์ข้อความเข้ามาในระบบ และให้คุณทำการแสดงการกลับตัวอักษรทั้งหมดที่ผู้ใช้กรอกมา เช่น ผู้ใช้กรอกมาว่า Hello World คุณจะต้องแสดงบนหน้าจอว่า dlroW olleH
    (กำหนดให้เขียนวิธีการสลับ โดยใช้ตัวแปรประเภท Pointer เท่านั้น)

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

void Swap ( char *n , char *n2 , int *len ) ;

int main () {
    char name1[ 100 ] , name2[ 100 ] ;
    printf( "Enter : " ) ;
    fgets( name1 , sizeof(name1) , stdin ) ;
    name1[ strcspn( name1 , "\n" ) ] = '\0' ;
    int len = strlen( name1 ) ;
    Swap( name1 , name2 , &len ) ;
    printf( "Output : " ) ;
    printf( "%s" , name2 ) ;
    return 0 ;
}//end main

void Swap ( char *n , char *n2 , int *len ) {
    for ( int i = 0 ; i < *len ; i++ ) {
        n2[ i ] = n[ *len - 1 - i ] ; 
    }//end for 
    n2[ *len ] = '\0';
}//end Swap

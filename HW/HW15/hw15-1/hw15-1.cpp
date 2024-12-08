/*
    จงเขียนโปรแกรมเพื่ออ่านค่าจากไฟล์ a15-1.txt แล้วนำมาแสดงผลบนโปรแกรม

    ข้อมูลภายในไฟล์ a.txt
        Hello World
    
    Output:
        Text in file = Hello World
*/

#include <stdio.h>

int main () {
    FILE *fp ;
    fp = fopen( "a15-1.txt" , "r" ) ;
    if ( fp == NULL ) {
        printf("ERR") ;
        return 0 ;
    }//end if err

    char name[ 200 ] ;
    printf( "Text in file = " ) ;
    while ( fgets( name , sizeof( name ) , fp ) != NULL ) {
        printf( "%s" , name ) ;
    }//end while print
    return 0 ;
}//end main

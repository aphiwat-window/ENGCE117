/*
    อ่านไฟล์และนำมาแสดงผลข้อมูลบนหน้าจอ

    ข้อมูลภายในไฟล์ a15-3.txt :
        Somchai	19	3.78	Male
        Somjing	18	3.54	Female
        Somjung	20	2.44	Male
    Output:
        Somchai	19	3.78	Male
        Somjing	18	3.54	Female
        Somjung	20	2.44	Male
*/

#include <stdio.h>

int main () {
    FILE *fp ;
    fp = fopen( "a15-3.txt" , "r" ) ;
    if ( fp == NULL ) {
        printf("ERR") ;
        return 0 ;
    }//end if err

    float Grade , Age ;
    char Name[ 20 ] , Sex[ 20 ] ;
    while ( fscanf( fp , "%s %f %f %s" , Name , &Age , &Grade , Sex ) != EOF ) {
        printf( "%s  %.0f  %.2f  %s\n" , Name , Age , Grade , Sex ) ;
    }//end while scan and print
    return 0 ;
}//end main

/*
    เขียนโปรแกรมหาข้อมูลผู้ที่เกรดเฉลี่ยเยอะที่สุดจากบุคคลในไฟล์ข้อมูล โดยให้แสดงข้อมูลเฉพาะชื่อกับเกรดเฉลี่ยเท่านั้น

    ข้อมูลภายในไฟล์ a15-4.txt :
        Somchai	19	3.78	Male
        Somjing	18	3.54	Female
        Somjung	20	2.44	Male
    Output:
        Somchai, Grade 3.78
*/
struct Person {
	char  Name[20] ;
    float Grade ;
    int Age ;
    char sex[20] ;
} ;
Person User[ 3 ] ;

#include <stdio.h>
#include <string.h>


int main () {
    FILE *fp ;
    fp = fopen( "a15-3.txt" , "r" ) ;
    if ( fp == NULL ) {
        printf("ERR") ;
        return 0 ;
    }//end if err

    float Mostgrade = -999 ;
    char MostName[ 20 ] ;

    for ( int i = 0; i < 3; i++) {
        fscanf( fp , "%s %d %f %d"  , User[ i ].Name , &User[ i ].Age , &User[ i ].Grade , User[ i ].sex  ) ;
        if ( User[ i ].Grade >= Mostgrade ) {
            Mostgrade = User[ i ].Grade ;
            strcpy( MostName , User[ i ].Name ) ;
        }//end if ใครคะแนนเยอะกว่า
    }//end for รับ 3 บรรทัด
    printf( "Output:\n" ) ;
    printf( "%s , Grade  %.2f" , MostName , Mostgrade ) ;
    return 0 ;
}//end main

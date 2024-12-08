/*
    จงอ่านค่าที่ได้จากไฟล์นำมาเพื่อนำมาคำนวณหาผลรวมที่ได้รับจากผู้ใช้

    ข้อมูลภายในไฟล์ a15-2.txt
        2

    Test case:
        Input vale from user to B:
            12
    Output:
        Read File to A is 2
        Input value from user is 12
        Answer = 14

    Test case:
        Input vale from user to B:
            20
    Output:
        Read File to A is 2
        Input value from user is 20
        Answer = 22
*/

#include <stdio.h>

int main () {
    FILE *fp ;
    fp = fopen( "a15-2.txt" , "r" ) ;
    if ( fp == NULL ) {
        printf("ERR") ;
        return 0 ;
    }//end if err

    int num1 , num2 ;
    fscanf( fp , "%d" , &num1 ) ;
    printf( "Input vale from user to B : " ) ;
    scanf( "%d" , &num2 ) ;
    printf( "Output:\nRead File to A is %d\n" , num1 ) ;
    printf( "Input value from user is %d\n" , num2 ) ;
    printf( "Answer = %d" , num1 + num2 ) ;
    return 0 ;
}//end main

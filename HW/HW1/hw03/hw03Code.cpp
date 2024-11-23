/*
    เขียนโปรแกรมรับ "ชื่อ" จากผู้ใช้ และแสดงผลบนหน้าจอดังผลลัพธ์ด้านล่างต่อไปนี้ 
    
    Test case:
        First Name: Aomsin
        Last Name: AomMoney
    Output:
        Aomsin AomMoneys TC, RMUTL, Chiang Mai, Thailand

    Test case:
        First Name: ABC
        Last Name: DEF
    Output:
        ABD DEFs TC, RMUTL, Chiang Mai, Thailand
*/

#include <stdio.h>

int main () {
    char Fistname[100] , Lastname[100] ;
    printf( "First Name: " ) ;
    scanf( "%s" , Fistname ) ;

    printf( "Last Name: " ) ;
    scanf( "%s" , Lastname ) ;

    printf("\n%s %s TC, RMUTL, Chiang Mai, Thailand" , Fistname , Lastname ) ;
}//end main

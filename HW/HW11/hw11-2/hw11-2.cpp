/*
    ผู้ใช้กรอกชื่อและอายุเข้าไปในระบบจำนวน 2 ครั้ง โดยให้คุณทำการสลับอายุของคน 2 คนนี้ผ่านฟังก์ชันที่คุณเขียนขึ้นมา เช่น นาย ก อายุ 31 ปี และ นาย ข อายุ 20 ปี หลังจากเรียกฟังก์ชันการสลับค่าแล้ว นาย ก จะอายุ 20 ปี และนาย ข จะอายุ 31 ปี

    Test case:
        Input A
        Name : 
            Yorn
        Age : 
            31
        Input B
        Name : 
            Thane
        Age : 
            20
    Output:
        ** RESULT **
        Name: Yorn (31)
        Name: Thane (20)

        ** SWAP AGE **
        Name: Yorn (20)
        Name: Thane (31)

*/

#include <stdio.h>
#include <string.h>

void PRINT ( char n[] , char n2[] , int a ,int a2 ) ;

int main () {

    int Age1 = 0, Age2 = 0, swap = 0 ;
    char name1[ 100 ] , name2[ 100 ] ;

    printf( "Enter name A : " ) ;
    scanf( "%s" , name1 ) ;
    printf( "Enter age : " ) ;
    scanf( "%d" , &Age1 ) ;
    printf( "Enter name B : " ) ;
    scanf( "%s" , name2 ) ;
    printf( "Enter age : " ) ;
    scanf( "%d" , &Age2 ) ;
    printf( "Output:\n** RESULT **\n" ) ;
    PRINT( name1 , name2 , Age1 , Age2 ) ;
    swap = Age1 ; Age1 = Age2 ; Age2 = swap ;
    printf( "\n** SWAP AGET **\n" ) ;
    PRINT( name1 , name2 , Age1 , Age2 ) ;
    return 0 ;
}//end main

void PRINT ( char n[] , char n2[] , int a , int a2 ) {
    printf( "Name : " ) ;
    for ( int i = 0 ; i < strlen(n) ; i++ ) {
        printf( "%c" , n[i] ) ;
    }//end for 
    printf( " (%d)\n" , a ) ;

    printf( "Name : " ) ;
    for ( int i = 0 ; i < strlen(n2) ; i++ ) {
        printf( "%c" , n2[i] ) ;
    }//end for 
    printf( " (%d)" , a2 ) ;
}//end PRINT

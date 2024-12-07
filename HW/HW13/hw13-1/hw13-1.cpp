/*
    ผู้ใช้กรอกชื่อและอายุเข้าไปในระบบจำนวน 2 ครั้ง โดยให้คุณทำการสลับอายุของคน 2 คนนี้ผ่านฟังก์ชันที่คุณเขียนขึ้นมา เช่น นาย ก อายุ 31 ปี และ นาย ข อายุ 20 ปี หลังจากเรียกฟังก์ชันการสลับค่าแล้ว นาย ก จะอายุ 20 ปี และนาย ข จะอายุ 31 ปี
    (กำหนดให้เขียนวิธีการสลับ 2 ค่านี้ โดยใช้ตัวแปรประเภท Pointer เท่านั้น)
    
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

void Swap ( int *Age1 , int *Age2 , int *swap ) ;

int main () {

    int Age1 = 0 , Age2 = 0 , swap = 0 ;
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
    printf( "Name : %s (%d)\n" , name1 , Age1 ) ;
    printf( "Name : %s (%d)\n** SWAP AGE **" , name2 , Age2 ) ;
    Swap( &Age1 , &Age2 , &swap ) ;
    printf( "\nName : %s (%d)\n" , name1 , Age1 ) ;
    printf( "Name : %s (%d)" , name2 , Age2 ) ;
    return 0 ;
}//end main

void Swap ( int *Age1 , int *Age2 , int *swap ) {
    *swap = *Age1;
    *Age1 = *Age2 ;
    *Age2 = *swap ;
}//end Swap

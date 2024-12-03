/*
    รับค่าจากผู้ใช้จำนวน 3 ค่า และสร้างฟังก์ชันในการหาผลรวมของจำนวน 3 ค่านี้ และแสดงผลลัพธ์มายังหน้าจอ พร้อมระบุชื่อฟังก์ชันที่เรียกใช้งาน เช่น รับค่า 3, 5, 6 จะแสดงผลลัพธ์ว่า 14 (Calculate by Additional Function)

    Test case:
        Input 1 : 
            3
        Input 2 : 
            4
        Input 3 : 
            5
    Output:
        Summation = 12 (Calculate by Additional Function)
*/

#include <stdio.h>

int cal ( int in1 , int in2 , int in3 ) ;

int main () {

    int input1 = 0, input2 = 0, input3 = 0 , sum ;

    printf( "Enter input 1 : " ) ;
    scanf( "%d" , &input1 ) ;
    printf( "Enter input 2 : " ) ;
    scanf( "%d" , &input2 ) ;
    printf( "Enter input 3 : " ) ;
    scanf( "%d" , &input3 ) ;

    sum = cal( input1 , input2 ,input3 ) ;
    printf( "Summation = %d (Calculate by cal Function) " , sum ) ;
    return 0 ;
}//end main

int cal ( int in1 , int in2 , int in3 ) {
    return in1 + in2 + in3 ;
}//end cal

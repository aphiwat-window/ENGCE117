/*
    จงเขียนโปรแกรมภาษาซีเพื่อรับข้อมูลจากผู้ใช้เป็นตัวเลข และให้แสดงชุดอนุกรมตามจำนวนตัวเลขที่กรอก พร้อมกับแสดงผลรวมของชุดอนุกรมนี้ 9 + 99 + 999 + 9999 + 9999 + .... เช่น ผู้ใช้กรอกเลข 5 ให้แสดงชุดอนุกรมคือ 9 + 99 + 999 + 9999 + 99999 และแสดงผลรวมคือ 111105
    (โจทย์ข้อนี้ให้ใช้ For Loop เท่านั้น)
    
    Test case:
        Enter number :
            5
    Output:
        Series = 9 + 99 + 999 + 9999 + 99999
        Sum = 111105

    Test case:
        Enter number :
            7
    Output:
        Series = 9 + 99 + 999 + 9999 + 99999 + 999999 + 9999999
        Sum = 11111103
*/

#include <stdio.h>

int main() {
    int input = 0 , cal = 9 , sum = 0 ;

    printf( "Enter start : " ) ;
    scanf( "%d" , &input ) ;

    printf( "Output:\n" ) ;
    printf( "Series = %d" , cal  ) ;
    sum += cal ;

    for ( int i = 2 ; i <= input ; i++ ) {
        cal = cal * 10 + 9 ;
        printf( " + %d" , cal ) ;
        sum += cal ;
    }//end for เพิ่มที่ละหลัก
    printf( "\nSum = %d" , sum ) ;

    return 0 ;
}//end main

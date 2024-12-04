/*
    จงสร้างฟังก์ชันเพื่อหาผลรวมของอนุกรม 1! + (1+2!) + (2+3!) + (3+4!) + (4+5!) + ... โดยโปรแกรมจะทำการรับค่าจำนวนพจน์ของอนุกรมมา และให้คุณสร้างฟังก์ชันในการหาผลรวม เช่น ผู้ใช้กรอกเลข 3 ก็ต้องแสดงผลรวมของอนุกรม 1! + (1+2!) + (2+3!)

    Test case:
        3
    Output:
        Sum = 12

    Test case:
        6
    Output:
        Sum = 888

*/

#include <stdio.h>

int cal ( int num , int sum ) ;

int main () {
    int data = 0 ;
    int sum = 0 ;
    printf( "Enter : " ) ;
    scanf( "%d" , &data ) ;
    sum = cal( data , sum ) ;
    printf( "Output:\nSum = " ) ;
    printf("%d" , sum ) ;
    return 0 ;
}//end main

int cal ( int num , int sum ) {
    int result = 1 , cal = 0 ;
    for ( int i = 1 ; i <= num ; ++i ) {
        result *= i ;
        sum += result + cal ;
        cal ++ ;
    }//end for คำนวน 
    return sum ;
}//end cal


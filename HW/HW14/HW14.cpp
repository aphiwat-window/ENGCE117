/*
    ให้เข้าโปรแกรมสุ่มตัวเลขเข้าไปใส่ในตัวแปรอาเรย์ขนาด N ช่อง โดยที่ตัวแปร N คือค่าที่ผู้ใช้กรอกเข้ามา จากนั้นให้คุณเขียนโปรแกรมเพื่อหาค่าที่มากที่สุด และค่าที่น้อยที่สุดภายในตัวแปรอาเรย์นี้ พร้อมทั้งแสดงข้อมูลทุกอย่างภายในอาเรย์ออกมา
    (กำหนดให้ค่าที่สุ่มมา มีช่วงข้อมูลอยู่ที่ 10-99 เท่านั้น)
    (กำหนดให้การแสดงผลแบบชิดขอบขวา 2 ช่องเท่านั้น)

    Test case:
        Input N : 
            11
    Output:
        Index:  0  1  2  3  4  5  6  7  8  9 10
        Array: 99 18 27 16 74 28 43 47 25 10 88

        Max = 99
        Min = 10

*/

#include <stdio.h>
#include <stdlib.h>  //เรียก Libary ของ Random
#include <time.h>//เรียก Libary ของ time

void Display ( int arr[] , int Max , int Min , int n ) ;

int main () {
    srand( time(NULL) ) ;
    int n , Max = -9999 , Min = 9999 , Array[ 100 ] ; 
    
    printf( "Input N : " ) ;
    scanf( "%d" , &n ) ;
    for ( int i ; i < n  ; i++ ) {
        Array[ i ] = rand() % (99 - 10 + 1) + 10 ;
        if ( Array[ i ] >= Max ) {
            Max = Array[ i ] ;
        } else if ( Array[ i ] <= Min ) {
            Min = Array[ i ] ;
        }//end if เลขไหนเยอะสุด
    }//end for random
    Display( Array , Max , Min , n ) ;
    return 0 ;
}//end main

void Display ( int arr[] , int Max , int Min , int n) {
    printf( "Output:\nIndex: " ) ;
    for ( int  i = 0 ; i < n ; i++ ) {
        printf( "%2d " , i ) ;
    }//end for print index
    printf( "\nArray: " ) ;
    for ( int  i = 0; i < n ; i++ ) {
        printf( "%2d " , arr[ i ] ) ;
    }//end for ปร้น arr
    printf( "\n\nMax = %d\nMin = %d" , Max , Min ) ;
}//end Display

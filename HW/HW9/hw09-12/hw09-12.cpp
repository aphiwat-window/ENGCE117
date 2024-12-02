/*
    ผู้ใช้กรอกค่า Matrix แบบลูกบาศก์ลงใน Matrix พร้อมกับบรรจุค่าลงไปจนครบ และแสดงค่าภายใน Matrix ... จากนั้นรับค่าการแสดงผลการเปลี่ยนแปลง Matrix โดยหากรับค่า 1 จากผู้ใช้ ให้แสดงด้านมุมซ้ายของ Matrix ด้วยเลข 0 ... หากผู้ใช้กรอก -1 ให้แสดงมุมขวาของ Matrix ด้วยเลขศูนย์ (ดูตัวอย่างการแสดงผลได้ใน Test Case)
    
    Test case:
        Input cube size : 
            3
        Input element :
            1 2 3
            4 5 6
            7 8 9
        Show zero (1=Left, -1=Right) :
            1
    Output:
        Matrix =
            1 2 3
            4 5 6
            7 8 9
        Left Matrix =
            1 0 0
            4 5 0
            6 8 9

    Test case:
        Input cube size : 
            4
        Input element :
            1 2 3 3
            2 5 9 9
            7 5 3 4
            2 1 3 1
        Show zero (1=Left, -1=Right) :
            -1
    Output:
        Matrix =
            1 2 3 3
            2 5 9 9
            7 5 3 4
            2 1 3 1
        Left Matrix =
            1 0 0 0
            2 5 0 0
            7 5 3 0
            2 1 3 1
*/
#include <stdio.h>

void Sourt ( int input1[][5] , int cube , int ROL ) ;

void Display ( int input1[][5] , int cube ) ;


int main() {

    int input1[100][5] , cube = 0 ;
    int ROL = 0 ; 
    printf( "Enter new element of Array : " ) ;
    scanf( "%d" , &cube ) ;
    for ( int i = 0 ; i < cube ; i++ ) {
        for ( int  j = 0 ; j < cube ; j++ ) {
            scanf( "%d" , &input1[i][j] ) ;
        }//end for
    }//end for arr1
    
    printf( "Show zero (1=Left, -1=Right) :\n" ) ;
    scanf( "%d" , &ROL ) ;

    printf( "\nOutput:\n" ) ;
    Display( input1 , cube ) ;
    Sourt( input1 , cube , ROL ) ;
    return 0 ;
}//end main

void Display ( int input1[][5] , int cube ) {
    for ( int i = 0 ; i < cube ; i++ ) {
        for ( int  j = 0; j < cube; j++ ) {
            printf("%d ", input1[i][j] ) ;
        }//end for ปริ้นแถว
        printf( "\n" ) ;
    }//end for ปริ้นหลัก
}//end Display


void Sourt ( int input1[][5] , int cube , int ROL ) {
    if ( ROL == 1) {
        for ( int i = 0 ; i < cube ; i++ ) {
            for ( int  j = 0; j < cube; j++ ) {
                if ( j < cube - i - 1) { // จะใส่ 0 ให้กับทุกค่าในคอลัมน์ที่น้อยกว่าและเท่ากับตำแหน่งปัจจุบันในแถว
                    input1[i][j] = 0 ;
                }//end if เติม 0 ผั่งซ้าย
            }//end for แถว
        }//end for หลัก
        printf( "Left Matrix =\n" ) ;
        Display( input1 , cube ) ;
    } else if ( ROL == -1) {
        for ( int i = 0 ; i < cube ; i++ ) {
            for ( int j = 0 ; j < cube ; j++ ) {
                if ( j >= i + 1 ) { // จะใส่ 0 ให้กับทุกค่าในคอลัมน์ที่มากกว่าและเท่ากับตำแหน่งปัจจุบันในแถว
                    input1[i][j] = 0;
                }//end if เติม 0 ผั่งขวา
            }//end for แถว
        }//end for หลัก
        printf( "Right Matrix =\n" ) ;
        Display( input1 , cube ) ;
    } else {
        printf( "\nErr" ) ;
    }//end if 
}

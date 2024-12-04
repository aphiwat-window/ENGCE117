/*
    เมื่อผู้ใช้กรอกตัวเลข ให้โปรแกรมแสดงผลรวมของชุดอนุกรม ที่มีตัวเลข 2 ลำดับก่อนหน้าบวกกัน (อนุกรมฟีโบนัชชี)
    (จงเขียนในรูปแบบของ Recursion Function)

    Test case:
        8
    Output:
        Series = 1 + 1 + 2 + 3 + 5 + 8 + 13 + 21
        Sum = 54

*/

#include <stdio.h>

void calculator (int input , int num , int sum , int before , int after ) ;

int main() {

    int input , n = 0, sum = 1 , before = 1, after = 0 ;
    printf( "Enter value :\n" ) ;
    scanf( "%d" , &input ) ;
    calculator ( input , n , sum , before , after ) ;
    
    return 0 ;
}//end main

void calculator ( int input , int num , int sum , int before , int after ) {
    printf( "Series = : " ) ;
    if ( input == 1 ) {
        printf( "%d" , sum ) ;
        num += sum ;
    } else {
        for ( int i = 0 ; i < input ; i++ ) {
            sum = before + after ;
            printf( "%d" , sum ) ;
            printf( i + 1 != input ? " + " : "" ) ; //ใช้ตรวจเงื่อนไขการวาง +
            before = after ;
            after = sum ;
            num += sum ;
        }//end for แสดงอนุกรมฟีโบนัชชี
    }//end if ถ้าเป็น 1
    printf( "\nSum = %d" , num ) ;
}//end calculator


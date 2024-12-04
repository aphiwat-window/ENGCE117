/*
    จากชุดข้อมูลต่อไปนี้ จงเขียนฟังก์ชันเมื่อหาค่ามากที่สุดภายในอาเรย์ โดยที่
        ฟังก์ชันแรก ให้สร้างฟังก์ชันแบบ Pass by value เพื่อหาค่าความสูงที่สุดในอาเรย์ Height
        ฟังก์ชันสอง ให้สร้างฟังก์ชันแบบ Pass by reference เพื่อหาค่าอายุที่มากที่สุดในอาเรย์ Age

    int Height[10] = { 159, 168, 191, 188, 154, 152, 167, 165, 178, 177 } ;
    int Age[10] = { 18, 19, 18, 17, 16, 18, 17, 18, 18, 18 } ;

    Test case:
        
    Output:
        Max Height = 191
        Max Age = 19

*/

#include <stdio.h>

int value ( int H[] , int V ) ;
void reference ( int (&A)[] , int &R ) ;


int main () {
    int valueE = -999 , RefE = -999 ;
    int Height[10] = { 159, 168, 191, 188, 154, 152, 167, 165, 178, 177 } ; 
    int Age[10] = { 18, 19, 18, 17, 16, 18, 17, 18, 18, 18 } ;

    valueE = value( Height , valueE ) ;
    reference( Age , RefE ) ;
    
    printf( "Output:\nMax Height = %d\nMax Age = %d" , valueE , RefE ) ;
    return 0 ;
}//end main


int value ( int H[] , int V ) {
    for ( int i = 0 ; i < 10 ; i++ ) {
        if ( H[ i ] > V ) {
            V = H[i] ;
        }//end if check
    }//end for
    return V ;
}//end value


void reference ( int (&A)[] , int &R ) {
        for ( int i = 0 ; i < 10 ; i++ ) {
        if ( A[ i ] > R ) {
            R = A[ i ] ;
        }//end if check
    }//end for
}//end reference

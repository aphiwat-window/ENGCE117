/*
    ผู้ใช้ทำการกรอกค่าที่ต้องการสร้างอาเรย์(Array1 และ Array2) และให้ทำการผสานอาเรย์ทั้งสองมาเป็นอาเรย์ใหม่(Array3) และแสดงผลลัพธ์หลังจากการผสานกันแสดงผลจากมากไปน้อย
    
    Test case:
        Enter element of Array1 :
            4
        --| Array1 [0] : 
            9
        --| Array1 [1] : 
            7
        --| Array1 [2] : 
            6
        --| Array1 [3] : 
            3
        Enter element of Array2 :
            5
        --| Array2 [0] : 
            2
        --| Array2 [1] : 
            3
        --| Array2 [2] : 
            5
        --| Array2 [3] : 
            8
        --| Array2 [4] : 
            9
    Output:
        Merge Array1 & Array2 to Array3
        Array3 = 9 9 8 7 6 5 3 3 2
    
    Test case:
        Enter element of Array1 :
            8
        --| Array1 [0] : 
            7
        --| Array1 [1] : 
            8
        --| Array1 [2] : 
            9
        --| Array1 [3] : 
            6
        --| Array1 [4] : 
            1
        --| Array1 [5] : 
            2
        --| Array1 [6] : 
            8
        --| Array1 [7] : 
            3
            
        Enter element of Array2 :
            6
        --| Array2 [0] : 
            2
        --| Array2 [1] : 
            1
        --| Array2 [2] : 
            3
        --| Array2 [3] : 
            5
        --| Array2 [4] : 
            3
        --| Array2 [5] : 
            6
    Output:
        Merge Array1 & Array2 to Array3
        Array3 = 9 8 8 7 6 6 5 3 3 3 2 2 1 1
*/

#include <stdio.h>

void sorut ( int arr3[] , int n  ) ;

int main() {

    int input1[100] , input2[100] , input3[100] , n = 0 , n2 = 0 , n3 = 0 ;

    printf( "Enter element of Array1 : " ) ;
    scanf( "%d" , &n ) ;
    for (int i = 0; i < n; i++) {
        printf( "--| Array1 [%d] : " , i ) ;
        scanf( "%d" , &input1[i] ) ;
    }//end for arr1

    printf( "\n" ) ;

    printf( "Enter element of Array2 : " ) ;
    scanf( "%d" , &n2 ) ;
    for (int i = 0; i < n2; i++) {
        printf( "--| Array2 [%d] : " , i ) ;
        scanf( "%d" , &input2[i] ) ;
    }//end for arr2

    n3 = n2 + n ;
    for ( int i = 0; i < n; i++ ) {
        input3[i] = input1[i] ;
    } for ( int i = 0; i < n2; i++) {
        input3[n+i] = input2[i] ;
    }//end cpy จาก 1 ไป 3 และ 2 ไป 3
    sorut( input3 , n3 ) ;
    return 0 ;
}//end main

void sorut ( int arr3[] , int n ) {
    int swap = 0 ;
    for ( int i = 0 ; i < n - 1 ; i++ ) {
        for ( int j = 0 ; j < n - i - 1 ; j++ ) {
            if ( arr3[j] < arr3[j + 1] ) { 
                swap = arr3[j] ;
                arr3[j] = arr3[j + 1] ;
                arr3[j + 1] = swap ; 
            } //end if น้อยไปมาก
        }//end if สลับ
    }//end if จำนวนรอบ

    printf( "Output:\n" ) ;
    printf( "Merge Array1 & Array2 to Array3\n" ) ;
    printf( "Array3 = " ) ;
    for ( int i = 0 ; i < n ; i++ ) {
        printf( "%d " , arr3[i] ) ;
    }//end for แสดง arr 3
}//end for sorut

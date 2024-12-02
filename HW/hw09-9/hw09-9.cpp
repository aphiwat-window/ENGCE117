/*
    ผู้ใช้กรอกจำนวนอาเรย์ 2 มิติขึ้นมา 2 ชุด และกรอกค่าภายในอาเรย์จนครบ จากนั้นให้คุณสร้างอาเรย์ที่ 3 ขึ้นมาเก็บผลรวมของอาเรย์ทั้ง 2 ชุดนี้ โดยกำหนดให้ Element ของ Array1 , Array2 และ Array3 เท่ากัน
    
    Test case:
        Array1 element : 
            3 3
        Input :
            1 2 3
            4 5 6
            7 8 9
        Array2 element : 
            3 3
        Input :
            1 1 1
            1 1 1
            1 1 1
    Output:
        Array1 + Array2 = Array3
            2 3 4
            5 6 7
            8 9 10

*/

#include <stdio.h>

int main() {

    int input1[100][5] , input2[100][5] ;
    int row1 = 0 , column1 = 0 , row2 = 0 , colume2 = 0 ;

    //รับค่า arr1
    printf( "Array1 element : " ) ; 
    scanf( "%d %d" , &row1 , &column1 ) ;
    printf( "Input : \n" ) ;
    for ( int i = 0 ; i < row1 ; i++ ) {
        for ( int j = 0 ; j < column1 ; j++ ) {
            scanf( "%d" , &input1[i][j] ) ;
        }//end for รับค่าแถว
    }//end for รับค่าหลัก

    //รับค่า arr2
    printf( "Array2 element : " ) ; 
    scanf( "%d %d" , &row2 , &colume2 ) ;
    printf( "Input : \n" ) ;
    for ( int i = 0 ; i < row2 ; i++ ) {
        for ( int j = 0 ; j < colume2 ; j++ ) {
            scanf( "%d" , &input2[i][j] ) ;
        }//end for รับค่าแถว
    }//end for รับค่าหลัก

    //ปริ้นค่า arr ที่ถูกรวม
    if ( row1 == row2 && column1 == colume2 ) {
        printf( "Output: \n" ) ; 
        printf( "Array1 + Array2 = Array3 \n" ) ; 
        for ( int i = 0 ; i < row1 ; i++ ) {
            for ( int j = 0 ; j < column1 ; j++ ) {
                printf( "%d " , input1[i][j] + input2[i][j] ) ;
            }//end for แสดงค่าแถว
            printf( "\n" ) ;
        }//end for แสดงค่าหลัก
    } else {
        printf( "Error: Invalid matrix input" ) ;
    }//end for ถ้า Metrix ไม่เท่ากัน
    return 0 ;
}//end main

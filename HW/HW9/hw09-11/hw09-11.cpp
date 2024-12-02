/*
    รับค่า Array จากผู้ใช้มา 2 ค่า และเติมค่าในอาเรย์ให้เต็มทั้ง 2 ค่า นั้นนั้นทำ Array1 มาคูณกับ Array2 แบบ Matrix (คุณสามารถหาข้อมูลการคูณ Matrix เพิ่มเติมได้ที่ลิงค์นี้ https://www.youtube.com/watch?v=Gocc4CriZdA)
    
    Test case:
        Array1 Value : 
            2 5
        Array1 element :
            2 5 3 8 3
            2 5 3 1 1
        Array2 Value : 
            5 2
        Array2 element :
            2 3
            4 4
            1 2
            1 1
            2 3
    Output:
        Array1
            2 5 3 8 3
            2 5 3 1 1
        Array2
            2 3
            4 4
            1 2
            1 1
            2 3
        Array1 x Array2
            41 49
            30 36

*/

#include <stdio.h>

void Display( int input1[][5] , int input2[][5] , int row1 , int column1 , int row2 , int colume2 ) ;

void Multiply( int input1[][5] , int input2[][5] , int row1 , int column1 , int row2 , int colume2 ) ;

int main() {

    int input1[100][5] , input2[100][5] , Output[100][5];
    int row1 = 0 , column1 = 0 , row2 = 0 , colume2 = 0 ;

    //รับค่า arr1
    printf( "Array1 Value : \n" ) ; 
    scanf( "%d %d" , &row1 , &column1 ) ;
    printf( "Input : \n" ) ;
    for ( int i = 0 ; i < row1 ; i++ ) {
        for ( int j = 0 ; j < column1 ; j++ ) {
            scanf( "%d" , &input1[i][j] ) ;
        }//end for รับค่าแถว
    }//end for รับค่าหลัก

    //รับค่า arr2
    printf( "Array2 Value : \n" ) ; 
    scanf( "%d %d" , &row2 , &colume2 ) ;
    printf( "Input : \n" ) ;
    for ( int i = 0 ; i < row2 ; i++ ) {
        for ( int j = 0 ; j < colume2 ; j++ ) {
            scanf( "%d" , &input2[i][j] ) ;
        }//end for รับค่าแถว
    }//end for รับค่าหลัก
  
    Display( input1 , input2 , row1 ,column1 , row2 , colume2 ) ;
    Multiply( input1 , input2 , row1 ,column1 , row2 , colume2 ) ;
}//end main

void Display( int input1[][5] , int input2[][5] , int row1 , int column1 , int row2 , int colume2 ) {
    printf( "\nOutput:" ) ;
    printf( "\nArray1 :\n" ) ; //arr input1
    for( int i = 0 ; i < row1 ; i++) {
        for( int j = 0 ; j < column1 ; j++ ) {
            printf( "%d " , input1[i][j] ) ;
        }//end for ปริ้นหลัก j
        printf( "\n" ) ;
    }//end for ปริ้นหลัก j

    printf( "\nArray2 :\n" ) ; //arr input1
    for( int i = 0 ; i < row2 ; i++) {
        for( int j = 0 ; j < colume2 ; j++ ) {
            printf( "%d " , input2[i][j] ) ;
        }//end for ปริ้นหลัก j
        printf( "\n" ) ;
    }//end for ปริ้นหลัก j
}//end display

void Multiply ( int input1[][5] , int input2[][5] , int row1 , int column1 , int row2 , int colume2 ) {
    int Output[100][5] ;
    if( column1 != row2 ) {
        printf( "\nMatrix1 and Matrix2 connot multiply\n" ) ;
    } else {   
        for( int i=0 ; i < row1 ; i++ ) {
            for( int j = 0 ; j < colume2 ; j++ ) {
                Output[i][j] = 0 ;
                for( int k = 0 ; k < column1 ; k++ ) {
                    Output[i][j] += input1[i][k] * input2[k][j] ;
                }//end for calculator
            }//end for columns
        }//end for rows


        printf( "\nMatrix1 x Matrix2 is : \n" ) ;
        for( int i = 0 ; i < row1 ; i++) {
            for( int j = 0 ; j < colume2 ; j++ ) {
                printf( "%d " , Output[i][j] ) ;
            }
            printf( "\n" ) ;
        }//end for
    }//end else
}//end Multiply


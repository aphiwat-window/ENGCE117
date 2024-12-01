/*
    ผู้ใช้กรอกค่าจำนวนที่ต้องการสร้างอาเรย์ พร้อมกับกรอกค่าภายในอาเรย์จนครบ จากนั้นให้คุณแสดงค่าที่มาก "เป็นอันดับสาม" ของภายในอาเรย์
    
    Test case:
        Enter new element of Array :
            5
        Input :
            5
        Input :
            3
        Input :
            2
        Input :
            1
        Input :
            9           
    Output:
        Array: 5 3 2 1 9
        The large 3rd element = 3

    Test case:
        Enter new element of Array :
            8
        Input :
            6
        Input :
            7
        Input :
            11
        Input :
            13
        Input :
            15
        Input :
            49
        Input :
            27
        Input :        
            18
    Output:
        Array: 6 7 11 13 15 49 27 18
        The large 3rd element = 18
*/
#include <stdio.h>

void sorut ( int arr[] , int n  ) ;

int main() {

    int input1[100] , n = 0 ;

    printf( "Enter new element of Array : " ) ;
    scanf( "%d" , &n ) ;
    for ( int i = 0 ; i < n ; i++ ) {
        printf( "Input : " ) ;
        scanf( "%d" , &input1[i] ) ;
    }//end for arr1

    printf( "Array : " ) ;
    for( int i = 0 ; i < n ; i++ ) {
        printf( "%d " , input1[i] ) ;
    }//end for arr1

    sorut( input1 , n ) ;

    printf( "\nThe large 3rd element = %d" , input1[2] ) ;
    return 0 ;
}//end main


void sorut ( int arr[] , int n ) {
    int swap = 0 ;
    for ( int i = 0 ; i < n - 1 ; i++ ) {
        for ( int j = 0 ; j < n - i - 1 ; j++ ) {
            if ( arr[j] < arr[j + 1] ) { 
                swap = arr[j] ;
                arr[j] = arr[j + 1] ;
                arr[j + 1] = swap ; 
            } //end if น้อยไปมาก
        }//end if สลับ
    }//end if จำนวนรอบ
}//end for sorut

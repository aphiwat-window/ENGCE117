/*
    จากอาเรย์เดิม ที่มีค่าอยู่ก่อนแล้วคือ { 9, 2, 6, 1, 7 } จงเขียนโปรแกรมเพื่อรับค่าจากผู้ใช้อีก N จำนวน เพื่อนำไปต่อในอาเรย์เดิม และจัดเรียงใหม่จากน้อยไปยังมาก
    
    Test case:
        Enter new element of Array :
            4
        Input :
            3
        Input :
            4
        Input :
            2
        Input :
            5
    Output:
        Old Array: 9 2 6 1 7
        New Array: 1 2 2 3 4 4 5 6 7 9
*/
#include <stdio.h>

void sorut ( int arr[] , int n  ) ;
void Mix ( int arr1[] , int arr2[] , int num ) ;

int main() {

    int input1[] = { 9, 2, 6, 1, 7 } , input2[100] , n = 0 ;

    printf( "Enter new element of Array : " ) ;
    scanf( "%d" , &n ) ;
    for (int i = 0; i < n; i++) {
        printf( "Input : " ) ;
        scanf( "%d" , &input2[i] ) ;
    }//end for arr1

    printf( "\n" ) ;

    printf( "Old Array : " ) ;
    for( int i = 0; i < 5; i++) {
        printf( "%d " , input1[i] ) ;
    }//end for arr2

    Mix( input1 , input2 , n ) ;

    sorut( input2 , n+5  ) ;

    printf( "\n" ) ;
    printf( "New Array : " ) ;
    for( int i = 0; i < n+5 ; i++) {
        printf( "%d " , input2[i] ) ;
    }//end for arr2

    return 0 ;
}//end main


void Mix ( int arr1[] , int arr2[] , int num ) {
    for ( int i = 0; i < 5; i++) {
        arr2[num+i] = arr1[i] ;
    }//end for ก็อป arr1 ใส่ arr2
}//end Mix

void sorut ( int arr[] , int n ) {
    int swap = 0 ;
    for ( int i = 0 ; i < n - 1 ; i++ ) {
        for ( int j = 0 ; j < n - i - 1 ; j++ ) {
            if ( arr[j] > arr[j + 1] ) { 
                swap = arr[j] ;
                arr[j] = arr[j + 1] ;
                arr[j + 1] = swap ; 
            } //end if น้อยไปมาก
        }//end if สลับ
    }//end if จำนวนรอบ
}//end for sorut

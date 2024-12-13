/*
    จงเขียนโปรแกรมอ่านค่าจากข้อมูลในไฟล์ แล้วนำมาแสดงบนหน้าจอ จากนั้นนำมาเรียงลำดับตามตัวอักษรจาก A-Z และเรียงข้อมูลจาก Z-A

    ข้อมูลภายในไฟล์ a15-8.txt :
        Thai
        Bird
        Ant
        Zero
        Wolf
        Cobra
        Orange
        Mango
        Yoyo
    Output:
        Normal (9 Item): Thai, Bird, Ant, Zero, Wolf, Cobra, Orange, Mango, Yoyo .
        Sort (A to Z)  : Ant, Bird, Cobra, Mango, Orange, Thai, Wolf, Yoyo, Zero .
        Sort (Z to A)  : Zero, Yoyo, Wolf, Thai, Orange, Mango, Cobra, Bird, Ant .
*/

#include <stdio.h>
#include <string.h>

void Display( char Dp[][100] , int n ) ;
void Maxmin( char arr[][100] , int ASCII[] , int n , int Order ) ;

int main () {
    FILE *fp ;
    fp = fopen( "a15-8.txt" , "r" ) ;
    if ( fp == NULL ) {
        printf("ERR") ;
        return 0 ;
    }//end if err

    int n = 0 , Order = 0 ;
    char data[ 100 ][ 100 ] ;
    int ASCII [ 100 ] ;
    

    while ( fscanf( fp , "%s" , data[ n ] )!= EOF ) {
       ASCII[ n ] = data[ n ][ 0 ] ;
       n++ ; 
    } //end while scan
    printf( "Output:\nNormal (%d Item): " , n ) ;
    Display( data , n ) ;
    printf( "Sort (A to Z)  : " ) ;
    Maxmin( data , ASCII , n , Order ) ;
    Order = 1 ;
    printf( "Sort (Z to A)  : " ) ;
    Maxmin( data , ASCII , n , Order ) ;

    return 0 ;
}//end main

void Maxmin( char arr[][ 100 ] , int ASCII[] , int n , int Order ) {
    char swap[ 100 ] ;
    int tempASCII;
    for ( int i = 0 ; i < n - 1 ; i++ ) {
        for ( int j = 0 ; j < n - i - 1 ; j++ ) {
            if ( Order == 1 && ASCII[j] < ASCII[ j + 1 ] || 
                 Order == 0 && ASCII[j] > ASCII[ j + 1 ] ) { 
                strcpy( swap , arr[ j ] ) ;
                strcpy( arr[ j ] , arr[ j + 1 ] ) ;
                strcpy( arr[ j + 1 ] , swap ) ;

                tempASCII = ASCII[j];
                ASCII[j] = ASCII[j + 1];
                ASCII[j + 1] = tempASCII;
            } //end if น้อยไปมาก
        }//end if สลับ
    }//end if จำนวนรอบ
    Display( arr , n ) ;
}//end Maxmin

void Display( char Dp[][100] , int n ) {
    for ( int i = 0 ; i < n ; i++) {
        printf( "%s" , Dp[ i ] ) ;
        if ( i + 1 != n ) 
        printf( ", " ) ;
    }//end for print , 
    printf( " ." ) ;
    printf( "\n" ) ;
}//end display

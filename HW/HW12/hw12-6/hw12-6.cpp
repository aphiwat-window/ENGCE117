/*
    ผู้ใช้กรอกชื่อและความสูงของคนในโรงเรียนในห้อง A และห้อง B และเรียงลำดับของคนที่ตัวเล็กที่สุดไปยังตัวใหญ่ที่สุดในแต่ละห้อง และเรียงลำดับของคนทั้งโรงเรียนจากตัวที่ใหญ่ที่สุดมายังตัวเล็กที่สุด

    Test case:
        Room A
        Name : 
            John
        Height (cm) : 
            176.6
        Name : 
            Job
        Height (cm) : 
            177.5
        Name : 
            Aim
        Height (cm) : 
            149.8
        Name : 
            Mon
        Height (cm) : 
            158.9
        Name : 
            Ammy
        Height (cm) : 
            151.0
        Name : 
            A
        Height (cm) : 
            169.7
        Name : 
            -1

        Room B
        Name : 
            Komsam
        Height (cm) : 
            176.1
        Name : 
            Samart
        Height (cm) : 
            165.4
        Name : 
            Sunu
        Height (cm) : 
            168.1
        Name : 
            -1

    Output:
        Room A -> Aim Ammy Mon A John Job
        Room B -> Samart Sunu Komsam
        School -> Job John Komsam A Sunu Samart Mon Ammy Aim
*/

#include <stdio.h>
#include <string.h>

struct Person {
	char Name[20] ;
    float Height ;
} ;
struct Person RoomA[ 100 ] ;
struct Person RoomB[ 100 ] ;
struct Person School[ 100 ] ;

int i = 0 , i2 = 0 ;

void scan () ;
void swap ( struct Person swap[] , int n ,int order ) ;

int main () {
    scan () ;
    printf( "\nOutput:\nRoom A -> " ) ;
    for ( int j = 0; j < i ; j++ ) {
        printf( "%s " , RoomA[ j ].Name ) ;
    }//end for
    printf( "\nRoom B -> " ) ;
    for ( int i = 0 ; i < i2 ; i++ ) {
        printf( "%s " , RoomB[ i ].Name ) ;
    }//end for
    printf( "\nSchool -> " ) ;
    for ( int j = 0 ; j < i2 + i ; j++ ) {
        printf( "%s " , School[ j ].Name ) ;
    }//end for
    return 0 ;
}//end main

void scan () {
    printf( "Room A\n" ) ;
    while ( 1 ) {
        printf( "Name [%d] : " , i + 1 ) ;
        scanf( "%s" , RoomA[ i ].Name ) ;
        if ( strcmp( RoomA[ i ].Name , "-1" ) == 0 ) {
            break ;
        }//end if ถ้ากรอก -1
        printf( "Height (cm) : " ) ;
        scanf( "%f" , &RoomA[ i ].Height ) ;
        printf( "------------------------\n" ) ;   

        strcpy( School[ i ].Name , RoomA[ i ].Name ) ;
        School[ i ].Height = RoomA[ i ].Height ;     
        i++ ;
    }//end while
    swap ( RoomA , i , 1 ) ; //เรียก funtion

    printf( "\nRoom B\n" ) ;
    while ( 1 ) {
        printf( "Name [%d] : " , i2 + 1 ) ;
        scanf( "%s" , RoomB[ i2 ].Name ) ;
        if ( strcmp( RoomB[ i2 ].Name , "-1" ) == 0 ) {
            break ;
        }//end if ถ้ากรอก -1
        printf( "Height (cm) : " ) ;
        scanf( "%f" , &RoomB[ i2 ].Height ) ;
        printf( "------------------------\n" ) ;   

        strcpy( School[ i2 + i ].Name , RoomB[ i2 ].Name ) ;
        School[ i2 + i ].Height = RoomB[ i2 ].Height ;     
        i2 ++ ;
    }//end while
    swap ( RoomB , i2 , 1 ) ; //เรียก funtion
    swap ( School , i2 + i , 0 ) ; //เรียก funtion
}

void swap ( struct Person swap[] , int n , int order ) {
    for ( int i = 0 ; i < n - 1 ; i++ ) {
        for ( int j = i + 1 ; j < n ; j++ ) {
            if ( order == 0 && swap[ i ].Height < swap[ j ].Height ||   // เรียงจากมากไปน้อย
                 order == 1 && swap[ i ].Height > swap[ j ].Height) {   //น้อยไปมาก
                struct Person temp = swap[ i ] ;
                swap[ i ] = swap[ j ] ;
                swap[ j ] = temp ;
            }//end if 
        }//end for j
    }//end for i
}//end swap

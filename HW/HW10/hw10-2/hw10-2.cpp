/*
    จงเขียนโปรแกรมเพื่อรับค่าอักขระจากผู้ใช้ทีละ 1 ตัวอักษรไปเรื่อยๆ เพื่อรับค่าใส่ไว้ภายในอาเรย์ แต่หากเจอตัวอักษร 'Y' หรือ 'y' ให้หยุดการทำงาน และแสดงค่าภายใน String ทันที

    Test case:
        Enter 1 character : 
            U
        Enter 1 character : 
            v
        Enter 1 character : 
            G
        Enter 1 character : 
            k
        Enter 1 character : 
            R
        Enter 1 character : 
            m
        Enter 1 character : 
            q
        Enter 1 character :
            Y
    Output:
        String = U v G k R m q

    Test case:
        Enter 1 character : 
            H
        Enter 1 character : 
            e
        Enter 1 character : 
            l
        Enter 1 character : 
            l
        Enter 1 character : 
            o
        Enter 1 character : 
            y
    Output:
        String = H e l l o
*/

#include <stdio.h>
#include <string.h>

int main () {
    char name[ 100 ] , input ;
    int data = 0 ;
    while ( 1  ) {
        printf( "Enter 1 character : \n" ) ;
        scanf( " %c" , &input) ;
        name[ data ] = input ; 
        data ++ ;
        if ( input == 'y' || input == 'Y' ) {
            name[ data ] = '\0';
            printf( "\nOutput:\nString = " ) ;
            for ( int  i = 0; i < data - 1 ; i++ ) {
                printf( " %c" , name[i] ) ;
            }//end for print
            break ;
        }//end if check
    }//end while loop 
    return 0 ;
 }//end main

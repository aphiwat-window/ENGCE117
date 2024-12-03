/*
    จงเขียนโปรแกรมเพื่อรับค่า String ที่สามารถรับชื่อและนามสกุลไว้ในตัวแปรเดียวกันได้ พร้อมกับแสดงผลบนหน้าจอคอมพิวเตอร์

    Test case:
        Kittinan Noimanee
    Output:
        Name: Kittinan Noimanee

    Test case:
        Visual Studio Code
    Output:
        Name: Visual Studio Code

*/

#include <stdio.h>
#include <string.h>

int main () {

    char name[100] ;

    printf( "Enter name : \n" ) ;
    fgets( name , sizeof(name) , stdin ) ;
    name[ strcspn( name , "\n" ) ] = '\0' ;
    int lengnt = strlen( name ) ;

    printf( "\nOutput\nName : " ) ;
    for ( int i = 0; i < lengnt ; i++) {
        printf( "%c" , name[i] ) ;
    }//end for ปริ้นค่า
    return 0 ;
 }//end main

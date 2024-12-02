/*
เขียนคำสั่งในการสร้างและเรียกใช้ฟังก์ชัน reverse() ตามโปรโตไทป์ต่อไปนี้ เพื่อนำข้อความจาก str1 มากลับอักขระหน้าไปหลัง และเก็บไว้ใน str2
ตัวอย่างเช่น str1 = "I love you"
จะได้ str2 = "uoy evol I"
*/

/*
#inclue <stdio.h>

void reverse( char str1[], char str2[] ) ;

int main() {
    char text[ 50 ] = "I Love You" ;
    char out[ 50 ] ;
    reverse( text, out ) ;
    return 0 ;
}//end function
*/

#include <stdio.h>
#include <string.h>

int reverse( char str1[] , char str2[] ) ;

int main() {
    char text[ 50 ] = "I Love You" ;
    char out[ 50 ] ;
    printf( "Input\n" ) ;
    fgets( text , sizeof( text ) , stdin ) ;  //รับค่า 
    text[ strcspn( text , "\n" ) ] = '\0' ;  //ลบ \n เป็น \0(หรือ Endnewline)
    reverse( text , out ) ;
    printf( "Output\n" ) ;
    printf( "%s" , out ) ;
    return 0 ;
}//end function

int reverse( char str1[] , char str2[] ) {
    int length = strlen( str1 ) ;
    for ( int i = 0 ; i < length ; i++ ) {
        str2[ i ] = str1[ length - 1 - i ] ; 
    } //end for reverse
    str2[ length ] = '\0' ;
    return 0 ;
}//end reverse
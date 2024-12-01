/*
เขียนคำสั่งในการสร้างและเรียกใช้ฟังก์ชัน reverse() ตามโปรโตไทป์ต่อไปนี้ เพื่อนำข้อความจาก str1 มากลับอักขระหน้าไปหลัง และเก็บไว้ใน str2
ตัวอย่างเช่น str1 = "I love you"
จะได้ str2 = "uoy evol I"
*/

#include <stdio.h>
#include <string.h>

char* reverse( char str1[]) ;

int main() {
    char text[ 50 ] = "I Love You" ;
    char *out ;
    printf( "Input\n" ) ;
    fgets(text, sizeof(text), stdin);  //รับค่า
    text[strcspn(text, "\n")] = '\0';  //ลบ \n
    out = reverse( text ) ;
    printf( "Output\n" ) ;
    printf("%s", out) ;
    
}//end function

char* reverse( char str1[] ) {
    static char reverse [50] ;
    int length = strlen(str1) ;

    for ( int i = 0 ; i < length ; i++ ) {
        reverse[i] = str1[ length - 1 - i ] ; 
    }
    return reverse ;
}//end reverse
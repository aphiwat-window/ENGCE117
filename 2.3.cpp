#include <stdio.h>
#include <string.h>

void explode( const char str1[] , const char splitter[] , char str2[][10] , int *count ) ;

int main() {
    char out[20][10] ;
    int num = 0 ;
    explode( "asdasd/adsa/sda" , "/" , out , &num ) ;//เรียกใช้งาน

    for ( int i = 0 ; i < num ; i++ ) {
       printf( "str2[%d] = \"%s\"\n" , i , out[i] ) ; 
    }//end for แสดงค่า
    printf( "count = %d" , num ) ;
    return 0 ;
}//end function

void explode( const char str1[] , const char splitter[] , char str2[][10] , int *count ) {
    char data[20] ;
    strcpy( data , str1 ) ;
    char *token = strtok( data , splitter ) ; //ตรวจว่าเจอตัวแบ่งตัวไหน
    if ( token == NULL ) { 
        printf( "count = 0" ) ; 
    } else {
        while ( token != NULL ) {
            strcpy( str2[*count] , token ) ; //ก็อปใส่ str2
            ( *count ) ++ ;
            token = strtok( NULL , splitter ) ; 
        }//end แยกคำ
    }//end if เช็คว่ามีตัวอักษรไหม
}//end explode

#include <stdio.h>
#include <string.h>

void explode( const char str1[] , const char splitter[] , char str2[][10] , int *count ) ;

int main() {
    char out[20][10] ;
    int num = 0 ;
    explode( "" , "/" , out , &num ) ;//เรียกใช้งาน

    for ( int i = 0 ; i < num ; i++ ) {
       printf( "str2[%d] = \"%s\"\n" , i , out[i] ) ; 
    }//end for แสดงค่า
    if ( num != 0 ) {
        printf( "count = %d" , num ) ;
    } else {
        printf( "count = 0" ) ; 
    }//end แสดงผล
    
    return 0 ;
}//end function

void explode( const char str1[] , const char splitter[] , char str2[][10] , int *count ) {
    char data[20] ;
    strcpy( data , str1 ) ;
    char *token = strtok( data , splitter ) ; //ตรวจว่าเจอตัวแบ่งตัวไหน
    while ( token != NULL ) {
            strcpy( str2[*count] , token ) ; //ก็อปใส่ str2
            ( *count ) ++ ;
            token = strtok( NULL , splitter ) ; 
        }//end แยกคำ
}//end explode

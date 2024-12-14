#include <stdio.h>
#include <string.h>

void explode( const char str1[] , const char splitter[] , char str2[][10] , int *count ) ; //ที่ const char ไม่ยอมให้เปลี่ยนแปลงค่าใน arr

int main() {
    char out[ 20 ][ 10 ] ;
    int num = 0 ;
    
    explode( "Hello/World" , "/" , out , &num ) ;//เรียกใช้งาน explode และส่งค่าไป

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
    char data[ 20 ] ; //สร้าง char ธรรมดา
    strcpy( data , str1 ) ; //ก็อปมาเพราะ const char ไม่ยอมให้ยุ่งกับตัวแปร
    char *token = strtok( data , splitter ) ; //ประกาศใช้ strtok ///เริ่มแยกหลังจากตัวแรก //คืนค่าเป็น Poiter
    while ( token != NULL ) { 
        strcpy( str2[*count] , token ) ; //ก็อปใส่ str2
        ( *count ) ++ ;
        token = strtok( NULL , splitter ) ; //เริ่มจากจุดที่ประกาศ //มองข้ามคำใน splitter  //มองเ string เป็นชุดเดัียว
    }//end แยกคำ
}//end explode

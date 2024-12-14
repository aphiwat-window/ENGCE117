#include <stdio.h>
#include <string.h>

void explode( char str1[] , char splitter[] , char str2[][ 10 ] , int *count ) ;

int main() {
    char in[ 100 ] , out[ 100 ][ 10 ] , splitter[ 100 ] ;
    int num = 0 ;
    printf( "Enter text : " ) ;
    fgets( in , sizeof( in ) , stdin ) ;  //รับค่า //ขนาดของ in
    printf( "Enter splitter : " ) ;
    fgets( splitter , sizeof( splitter ) , stdin ) ;  //รับค่า splitter
    in[ strcspn( in , "\n" ) ] = '\0' ; //ลบ \n แล้วเปลี่ยนเป็น \0  \0 = จบบรรทัด

    explode( in , splitter , out , &num) ; //เรียกใช้งาน explode

    for (int i = 0 ; i < num ; i++) {   //เอาไว้เช็คว่าถ้าไม่เจอตัวว่าง
       printf( "str2[%d] = \"%s\"\n" , i , out[i] ) ; 
    }//end for แสดงค่า
     if ( num != 0 ) {
        printf( "count = %d" , num ) ;
    } else {
        printf( "count = 0" ) ; 
    }//end แสดงผล
    return 0 ;
}//end function

void explode( char str1[] , char splitter[] , char str2[][10] , int *count ) {
    char *token = strtok( str1 , splitter ) ; //ประกาศใช้ strtok ///เริ่มแยกหลังจากตัวแรก //คืนค่าเป็น Poiter
        while ( token != NULL ) {
            strcpy( str2[ *count ] , token ) ; //ก็อปใส่ str2
            ( *count ) ++ ;
            token = strtok( NULL , splitter ) ;  //เริ่มจากจุดที่ประกาศ //มองข้ามคำใน splitter  //มองเ string เป็นชุดเดัียว
        }//end แยกคำ
}//end explode
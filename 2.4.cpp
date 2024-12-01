#include <stdio.h>
#include <string.h>

void explode( char str1[] , char splitter[] , char str2[][10] , int *count ) ;

int main() {
    char in[100] , out[100][10] , splitter[100] ;
    int num = 0 ;
    printf( "Enter text : " ) ;
    fgets( in , sizeof( in ) , stdin ) ;  //รับค่า
    printf( "Enter splitter : " ) ;
    fgets( splitter , sizeof( splitter ) , stdin ) ;  //รับค่า
    in[ strcspn( in , "\n" ) ] = '\0' ; 


    explode( in , splitter , out , &num) ; //เรียกใช้งาน explode

    for (int i = 0 ; i < num ; i++) {
       printf( "str2[%d] = \"%s\"\n" , i , out[i] ) ; 
    }//end for แสดงค่า
    printf( "count = %d" , num ) ;
    return 0 ;
}//end function

void explode( char str1[] , char splitter[] , char str2[][10] , int *count ) {
    char *token = strtok( str1 , splitter ) ; //เช็คค่า splitter
    if ( token == NULL ) {
        printf( "count = 0" ) ; 
    } else {
        while (token != NULL) {
            strcpy( str2[*count] , token ) ; //ก็อปใส่ str2
            ( *count ) ++ ;
            token = strtok( NULL , splitter ) ; 
        }//end แยกคำ
    }//end if เช็คว่ามีตัวอักษรไหม
}//end explode
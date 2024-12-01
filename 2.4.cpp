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
     if ( num != 0 ) {
        printf( "count = %d" , num ) ;
    } else {
        printf( "count = 0" ) ; 
    }//end แสดงผล
    return 0 ;
}//end function

void explode( char str1[] , char splitter[] , char str2[][10] , int *count ) {
    char *token = strtok( str1 , splitter ) ; //เช็คค่า splitter
        while (token != NULL) {
            strcpy( str2[*count] , token ) ; //ก็อปใส่ str2
            ( *count ) ++ ;
            token = strtok( NULL , splitter ) ; 
        }//end แยกคำ
}//end explode

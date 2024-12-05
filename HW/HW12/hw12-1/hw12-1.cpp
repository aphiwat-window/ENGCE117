/*
    สร้าง Struct เพื่อเก็บข้อมูลของคน 2 คน โดยเก็บข้อมูล ชื่อ , อายุ , เพศ และคะแนนสะสม และแสดงผลออกมาบนหน้าจอ
    
    struct Person {
	    char  Name[20] ;
	    int   Age ;
	    int   Sex ;
	    float Score ;
	} ;
    
    Test case:
        Person A
        Name : 
            Mai
        Age : 
            24
        Sex : 
            M
        Score : 
            99.99

        Person B
        Name : 
            Mon
        Age : 
            21
        Sex : 
            F
        Score : 
            87.60

    Output:
        --| Person A Information |--
        Name : Mai (M)
        Age : 24 years old
        Score : 99.99 points
        --| Person B Information |--
        Name : Mon (F)
        Age : 21 years old
        Score : 87.60 points
*/
#include <stdio.h>

struct Person {
	char  Name[20] ;
	int   Age ;
	char   Sex[2] ;
	float Score ;
} ;

Person User[ 2 ] ;


int main () {

    char text = 'A' ;

    for ( int  i = 0; i < 2; i++ ) {
        printf( "Person %c\n" , text ) ;
        printf( "Enter name : " ) ;
        scanf( "%s" , User[ i ].Name ) ;
        printf( "Enter Age : " ) ;
        scanf( "%d" , &User[ i ].Age ) ;
        printf( "Enter Sex : " ) ;
        scanf( "%s" , User[ i ].Sex ) ;
        printf( "Enter Score : " ) ;
        scanf( "%f" , &User[ i ].Score ) ;
        text = 'B' ;
    }//end for scan
    text = 'A' ;
    printf( "Output:\n" ) ;
    for ( int i = 0; i < 2 ; i++ ) {
        printf( "--| Person %c Information |--\n" , text ) ;
        printf( "Name : %s (%s)\n" , User[ i ].Name , User[ i ].Sex ) ;
        printf( "Age : %d years old\n" , User[ i ].Age  ) ;
        printf( "Score : %.2f points\n" , User[ i ].Score ) ;
        text = 'B' ;
    }//end for print 
    return 0 ;
}//end main

/*
    สร้าง Struct เพื่อเก็บข้อมูลของคน 2 คน โดยเก็บข้อมูล ชื่อ , อายุ , เพศ และคะแนนสะสม และแสดงผลออกมาบนหน้าจอ
    
    Test case:
        Student A
        Name : 
            Yorn
        Score : 
            21.42

        Student B
        Name : 
            Omen
        Score : 
            56.00

        Student C
        Name : 
            Alice
        Score : 
            80.75

        Student D
        Name : 
            Violet
        Score : 
            67.76

    Output:
        Alice Violet Omen Yorn
        80.75 67.76 56.00 21.42

    Test case:
        Student A
        Name : 
            Payna
        Score : 
            77.77
            
        Student B
        Name : 
            Zanis
        Score : 
            88.88

        Student C
        Name : 
            Lubu
        Score : 
            66.66

        Student D
        Name : 
            Krixi
        Score : 
            99.99

    Output:
        Krixi Zanis Payna Lubu
        99.99 88.88 77.77 66.66

*/

#include <stdio.h>

struct Person {
	char  Name[20] ;
	float Score ;
} ;

struct Person User[ 4 ] ;

void swap ( struct Person User[] ) ;

int main () {

    char TEXT[] = { 'A' , 'B' , 'C' , 'D' } ;

    for ( int  i = 0; i < 4; i++ ) {
        printf( "Student %c\n" , TEXT[ i ] ) ;
        printf( "Enter name : " ) ;
        scanf( "%s" , User[ i ].Name ) ;
        printf( "Enter Score : " ) ;
        scanf( "%f" , &User[ i ].Score ) ;
    }//end for scan
    swap( User ) ;
    printf("Output:\n");
    for ( int i = 0 ; i < 4 ; i++ ) {
        printf( "%s " , User[ i ].Name ) ;
    }//end for name
    printf( "\n" ) ;
    for ( int i = 0; i < 4 ; i++ ) {
        printf( "%.2f " , User[ i ].Score ) ;
    }//end for score
    
    return 0 ;
 
}//end main

void swap ( struct Person User[] ) {
    for ( int i = 0 ; i < 4 - 1 ; i++ ) {
        for ( int j = i + 1 ; j < 4 ; j++) {
            if ( User[ i ].Score < User[ j ].Score ) { // เรียงจากมากไปน้อย
                struct Person temp = User[ i ] ;
                User[ i ] = User[ j ] ;
                User[ j ] = temp ;
            }//end if 
        }//end for j
    }//end for i
}//end swap

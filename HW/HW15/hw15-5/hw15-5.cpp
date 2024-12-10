/*
    จงหาอายุเฉลี่ยจากข้อมูลของผู้ที่มีรายชื่ออยู่ในไฟล์ พร้อมระบุชื่อของผู้ที่มีอายุมากกว่าค่าเฉลี่ยทุกคน นับจากอายุมากไปยังอายุน้อย พร้อมกับแสดงอายุและเงินเดือนของเขาดังข้อมูลด้านล่างนี้

    ข้อมูลภายในไฟล์ a15-5.txt :
        Name	Age	Salary		Job
        Pong	32	45,000		Programmer
        Som		25	23,000		Support
        Aoy		24	33,250		Advisor
        Ying	26	34,550		Programmer
        Yot		28	50,000		Founder
        Pot		31	24,500		HR
        Vip		25	25,450		Programmer
    Output:
        Average : 27.29 Years
        Pong(32) : 45,000 Bath
        Pot(31) : 24,500 Bath
        Yot(28) : 50,000 Bath
*/

#include <stdio.h>

struct Person {
	char  Name[ 100 ] ;
    int Age ;
    char Salary[ 100 ] ;
    char job[ 100 ] ;
} ;
Person User[ 100 ] ;

void swap ( struct Person swap[] , int n ) ;

int main () {
    FILE *fp ;
    fp = fopen( "a15-5.txt" , "r" ) ;
    if ( fp == NULL ) {
        printf( "ERR" ) ;
        return 0 ;
    }//end if err
    int n ;
    float Average ;

    while ( fscanf( fp , "%s %d %s %s" , User[ n ].Name , &User[ n ].Age , User[ n ].Salary , User[ n ].job ) != EOF ) {
        //printf( "%5s %10d %10s %20s\n" , User[ n ].Name , User[ n ].Age , User[ n ].Salary , User[ n ].job ) ;
        Average += User[n].Age ;
        n++ ;
    }//end while scan and print
    Average /= n ;
    swap ( User , n ) ; //เรียก funtion
    printf( "Output:\nAverage : %.2f Years\n" , Average ) ;
    for ( int  i = 0; i < n ; i++ ) {
        if ( User[ i ].Age > Average ) {
            printf( "%s(%d) : %s Bath\n" , User[ i ].Name , User[ i ].Age , User[i].Salary  ) ;
        }//end if ถ้าอายุมากกว่าค่าเฉลี่ย
    }//end for ปริ้นตามจำนวน stuck
    return 0 ;
}//end main


void swap ( struct Person swap[] , int n ) {
    for ( int i = 0 ; i < n - 1 ; i++ ) {
        for ( int j = i + 1 ; j < n ; j++ ) {
            if ( swap[ i ].Age < swap[ j ].Age ) {// เรียงจากมากไปน้อย) 
                struct Person temp = swap[ i ] ;
                swap[ i ] = swap[ j ] ;
                swap[ j ] = temp ;
            }//end if 
        }//end for j
    }//end for i
}//end swap

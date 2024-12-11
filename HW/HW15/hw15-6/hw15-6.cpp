/*
    จงเขียนโปรแกรมเพื่อหาข้อมูลจากไฟล์เพื่อคำนวณหาเงินเดือนของสายอาชีพที่มีซ้ำกันในไฟล์ เพื่อหาว่าในสายอาชีพนั้นใครได้เงินเดือนเยอะที่สุด และระบุค่าเฉลี่ยของเงินเดือนทั้งบริษัทว่ามีเท่าไหร่

    ข้อมูลภายในไฟล์ a15-6.txt :
        Name    Age	Salary		Job
        Pong	32	45,000		Programmer
        Som		25	23,000		Support
        Aoy		24	33,250		Support
        Ying	26	34,550		Programmer
        Yot		28	50,000		Founder
        Pot		31	24,500		HR
        Vip		25	25,450		Programmer

    Output:
        Programmer: Pong(32 yrs) 45,000.00 Bath
        Support: Aoy(24 yrs) 33,250.00 Bath
        Average Salary: 33,678.57 Bath
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char  Name[ 100 ] ;
    int Age ;
    char Salarytxt[ 100 ] ;
    float Salary ;
    char job[ 100 ] ;
} ;
Person User[ 100 ] ;

void Most ( int n ) ;
void Display ( float arr[] , int count[] , char Name[][ 100 ] , int Age[] ) ;
void decimal ( float data ) ;


int main () {

    FILE *fp ;
    fp = fopen( "a15-6.txt" , "r" ) ;
    if ( fp == NULL ) {
        printf( "ERR" ) ;
        return 0 ;
    }//end if err

    int n = 0 ;
    float Average = 0 ;
    char convert[ 100 ] ;

    while ( fscanf( fp , "%s %d %s %s" , User[ n ].Name , &User[ n ].Age , User[ n ].Salarytxt , User[ n ].job ) != EOF ) {
        memset( convert , 0 , sizeof(convert) ) ; //ล้างค่าครั้งก่อน
    
        for ( int i = 0 ; User[ n ].Salarytxt[ i ] ; i++ ) {
            if ( User[ n ].Salarytxt[ i ] != ',') {
                strncat( convert, &User[ n ].Salarytxt[ i ] , 1) ;
            }//end if ก็อปลงใน Convert แบบที่ไม่มี ,
        }//end for วนรับค่าของ salartxt
    
        User[ n ].Salary = atof( convert ) ; //แปลงเป็น float
        Average += User[ n ].Salary ;
        //printf( "%5s %10d %10d %20s\n" , User[ n ].Name , User[ n ].Age , User[ n ].Salary , User[ n ].job ) ;
        n++ ;
    }//end while scan and print
    Average /= n - 4 ;

    fclose( fp ) ; 
    Most( n ) ;
    decimal ( Average ) ;

    return 0 ;
}//end main


void Most( int n) {
    char str0[] = "Programmer" , str1[] = "Support" ;
    char str2[] = "Founder" , str3[] = "HR" ;
    char Name[ 100 ][ 100 ] ;
    int count[ 4 ] = {0} ;
    int Age[ 4 ] = {0} ;
    float arrMax[ 4  ] = { -999 , -999 , -999 , -999 } ;

    for ( int  i = 0 ; i < n ; i++ ) {
        if ( strcmp(User[ i ].job , str0 ) == 0 ) { //Programmer
            count[ 0 ] ++ ;
            if ( User[ i ].Salary > arrMax[ 0 ] ) {
                strcpy( Name[ 0 ] , User[ i ].Name ) ;
                Age[ 0 ] = User[ i ].Age ;
                arrMax[ 0 ] = User[ i ].Salary ;
            }//end if เอาค่าเงินเดือนมากสุดของ Programmer เก็บ
            
        } else if ( strcmp( User[ i ].job , str1 ) == 0 ) { //Support
            count[ 1 ] ++ ;
            if ( User[ i ].Salary > arrMax[ 1 ] ) {
                strcpy( Name[ 1 ] , User[ i ].Name ) ;
                Age[ 1 ] = User[ i ].Age ;
                arrMax[ 1 ] = User[ i ].Salary ;
            }//end if เอาค่าเงินเดือนมากสุดของ Support เก็บ

        } else if ( strcmp( User[ i ].job , str2 ) == 0 ) { //Founder
            count[ 2 ] ++ ;
            if ( User[ i ].Salary > arrMax[ 2 ] ) {
                strcpy( Name[ 2 ] , User[ i ].Name ) ;
                Age[ 2 ] = User[ i ].Age ;
                arrMax[ 2 ] = User[ i ].Salary ;
            }//end if เอาค่าเงินเดือนมากสุดของ Founder เก็บ

        } else if (strcmp(User[ i ].job , str3 ) == 0 ) { //HR
            count[ 3 ] ++ ;
            if ( User[ i ].Salary > arrMax[ 3 ] ) {
                strcpy( Name[ 3 ] , User[ i ].Name ) ;
                Age[ 3 ] = User[ i ].Age ;
                arrMax[ 3 ] = User[ i ].Salary ;
            }//end if เอาค่าเงินเดือนมากสุดของ HR เก็บ
        }//end if
    }//end for วนรับค่า
    Display( arrMax , count , Name , Age ) ;
}//end Most


void Display ( float arr[] , int count[] , char Name[][ 100 ] , int Age[] ) {
    printf( "Output : \n" ) ;
    if ( count[ 0 ] > 1 ) {
        printf( "Programmer : %s(%d yrs) " , Name[ 0 ] , Age[ 0 ] ) ;
        decimal( arr[ 0 ] ) ;
    }//end if ค่า Programmer ซ้ำไหม
    if ( count[ 1 ] > 1 ) {
        printf( "Support : %s(%d yrs) " , Name[ 1 ] , Age[ 1 ] ) ;
        decimal( arr[ 1 ] ) ;    
    }//end if ค่า Support ซ้ำไหม
    if ( count[ 2 ] > 1 ) {
        printf( "Founder : %s(%d yrs) " , Name[ 2 ] , Age[ 2 ] ) ;
        decimal( arr[ 2 ] ) ; 
    } //end if ค่า Founder ซ้ำไหม
    if ( count[ 2 ] > 1 ) {
        printf( "HR : %s(%d yrs) " , Name[ 3 ] , Age[ 3 ] ) ;
        decimal( arr[ 3 ] ) ;     
    }//end if ค่า HR ซ้ำไหม
    printf( "Average Salary: " ) ;
}//end display


void decimal ( float data ) {
    char Convert[ 100 ] ;
    sprintf( Convert , "%.2f" , data ) ; //แปลงเป็น string
    int length = strlen( Convert ) ; //วัดความยาว
    for (int i = 0 ; i < length - 3 ; i++ ) { //กำหนดว่าจะพิมกี่ตัว
        if ( i != 0 && ( length - i ) % 3 == 0 ) { //กำหนดว่าถ้าครบ 3 ตัวให้พิม ,
            printf( "," ) ;
        }//end if
        printf( "%c" , Convert[ i ] ) ; 
    }//end for 
    printf( "%s Bath\n" , strchr( Convert, '.' ) ) ; //พิมข้อความทั้งหมดหลังจ
}//end decimal

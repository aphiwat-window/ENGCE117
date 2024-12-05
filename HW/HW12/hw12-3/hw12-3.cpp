/*
    ผู้ใช้กรอกข้อมูลพนักงานในบริษัท โดยจะกรอกข้อมูล ชื่อ, เงินเดือน, อายุการทำงาน ของแต่ละคน โดยเมื่อผู้ใช้กรอกตัว n จะถือเป็นการหยุดโปรแกรมและทำการแสดงข้อมูลเงินเดือนเฉลี่ยของพนักงานในบริษัท และเงินเดือนของทุกคนรวมกันที่ผู้บริหารต้องจ่าย และแสดงคนที่อายุงานเยอะที่สุดพร้อมระบุ ชื่อ เงินเดือน และอายุงาน ของคนๆ นั้น
    
    Test case:
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Yorn
        Salary (Bath/Month) : 
            15000
        Duration (Year) : 
            4
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Van
        Salary (Bath/Month) : 
            14550
        Duration (Year) : 
            2
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Thane
        Salary (Bath/Month) : 
            22500
        Duration (Year) : 
            8
        Do you want to Enter Employee Information? (y/n) : 
            n
    Output:
        Average of Salary : 17,350.00 Bath
        Payment of every month : 52,050.00 Bath
        ----------------------------------------
        ** Most duration in this business **
        Name : Thane (8 Years)
        Salary : 22,500.00 Bath

*/

//TODO: #21 output money should in decimal format (eg. 120,200,340.42).

#include <stdio.h>
#include <string.h>

struct Person {
	char  Name[20] ;
    int Duration ;
	float Salary ;
} ;

struct Person User[ 100 ] ;

void swap ( struct Person User[] ) ;
void decimal ( float data ) ;
void display ( float AVG , float SUM , int SA , int DU ,char NM[] ) ;

int main () {
int i = 0 , MostDuration ;
float Payment = 0 , Average , MostSalary ;
char yesorno , MostName[ 20 ] ;

    while ( 1 ) {
        printf( "Enter name : " ) ;
        scanf( "%s" , User[ i ].Name ) ;
        printf( "Salary (Bath/Month) : " ) ;
        scanf( "%f" , &User[ i ].Salary ) ;
        printf( "Duration (Year) : " ) ;
        scanf( "%d" , &User[ i ].Duration ) ;
        Payment += User[ i ].Salary ;

        if ( User[ i ].Duration >= MostDuration ) {
            MostSalary = User[ i ].Salary ;
            MostDuration = User[ i ].Duration ;
            strcpy( MostName , User[ i ].Name  ) ;
        }//end if check most MostDuration
        i++ ;
        printf( "Do you want to Enter Employee Information? (y/n) : " ) ;
        getchar() ;
        scanf( "%c" , &yesorno ) ;
        if ( yesorno == 'n' || yesorno == 'N' ) 
            break ;
        printf( "---------------------------------------------\n" ) ;
    }//end while
    Average = Payment / i ;
    display( Average , Payment , MostSalary , MostDuration , MostName ) ;
}//end main

void display ( float AVG , float SUM , int SA , int DU , char NM[] ) {
    printf( "Output\n" ) ;
    printf( "Average of Salary : " ) ;
    decimal ( AVG ) ;
    printf( "Payment of every month : " ) ;
    decimal ( SUM ) ;
    printf( "----------------------------------------\n** Most duration in this business **\n" ) ;
    printf( "Name : %s (%d Years)\n" , NM , DU) ; 
    printf( "Salary : ") ;
    decimal ( SA ) ;
}//end display


void decimal ( float data ) {
    char Convert[ 100 ] ;
    sprintf( Convert , "%.2f" , data ) ; //แปลงเป็น string
    int length = strlen( Convert ) ; //วัดความยาว
    for (int i = 0 ; i < length - 3 ; i++ ) { //กำหนดว่าจะพิมกี่ตัว
        if (i != 0 && ( length - i ) % 3 == 0 ) { //กำหนดว่าถ้าครบ 3 ตัวให้พิม ,
            printf( "," ) ;
        }//end if
        printf( "%c" , Convert[ i ] ) ; 
    }//end for 
    printf( "%s Bath\n" , strchr( Convert, '.' ) ) ; //พิมข้อความทั้งหมดหลังจ
}//end decimal

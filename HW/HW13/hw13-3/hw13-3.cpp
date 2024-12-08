/*
    HR ของบริษัทเน็ตเวิร์คทำการกรอกข้อมูลพนักงานลงไปในระบบคำนวณฐานภาษีเพื่อเตรียมส่งยอดภาษีสู่ฝ่ายบัญชี โดยจะหักภาษี ณ ที่จ่าย 7% ของเงินเดือนที่ได้ ให้คุณคำนวณภาษีพนักงานทั้งหมดที่บริษัทของคุณต้องชำระภายในปีนี้ (กรอกเลข -1 ถือเป็นการสิ้นสุดการกรอก และทำการสรุปผลภาษีที่ต้องชำระภายในปีนี้) และสร้างฟังก์ชันที่ระบุคนที่ต้องชำระภาษีเยอะที่สุดในบริษัทมาแสดงในผลสรุปยอดของบริษัทด้วย
    (กำหนดให้ฟังก์ชันที่สร้างขึ้น ห้ามมีการใช้คำสั่ง return แต่สามารถส่งผ่านค่าแบบ pass by reference ได้เท่านั้น)
    
    Test case:
        Employee 1's Name : 
            Omar
        Sarary (Bath/Month) : 
            12750
        Employee 2's Name : 
            Alice
        Sarary (Bath/Month) : 
            15900
        Employee 3's Name : 
            Max
        Sarary (Bath/Month) : 
            19860
        Employee 4's Name : 
            -1
    Output:
        All salary per month: 48,510.00 Bath
        All salary per year: 582,120.00 Bath
        Tax (7% per year) : 40,748.40 Bath
        Most tax in company : Max (16,682.40 Bath per year)

    Test case:
        Employee 1's Name : 
            John
        Sarary (Bath/Month) : 
            15780
        Employee 2's Name : 
            Oven
        Sarary (Bath/Month) : 
            16890
        Employee 3's Name : 
            May
        Sarary (Bath/Month) : 
            17870
        Employee 4's Name : 
            Bill
        Sarary (Bath/Month) : 
            22100
        Employee 5's Name : 
            -1
    Output:
        All salary per month: 72,640.00 Bath
        All salary per year: 871,680.00 Bath
        Tax (7% per year) : 61,017.60 Bath
        Most tax in company : Bill (18,564.00 Bath per year)
*/

#include <stdio.h>
#include <string.h>

struct Person {
	char Name[20] ;
    float Salary ;
} ;

struct Person User[ 100 ] ;

void display( float *sum_month , float *most_salary , char Most_name[] ) ;
void sort ( float *data) ;

int main () {
    float most_salary = -9999 , sum_month ;
    char Most_name[ 100 ] ;
    int i = 0 ;
    while ( 1 ) {
        printf( "Employee [%d] Name : " , i + 1 ) ;
        scanf( "%s" , User[ i ].Name ) ;
        if ( strcmp( User[i].Name , "-1" ) == 0 ) {
            break ;
        }//end if ถ้ากรอก -1
        printf( "Sarary (Bath/Month) : " ) ;
        scanf( "%f" , &User[ i ].Salary ) ;
        printf( "------------------------\n" ) ;
        sum_month += User[ i ].Salary ;
        if ( User[ i ].Salary > most_salary ) {
            most_salary = User[ i ].Salary ;
            strcpy( Most_name , User[ i ].Name ) ; 
        }//end หาใครเงินเยอะสุด
        i++ ;
    }//end while
    display( &sum_month , &most_salary , Most_name ) ;
    return 0 ;
}//end main

void display( float *sum_month , float *most_salary , char Most_name[] ) {
    printf( "Output:\nAll salary per month: " ) ;
    sort( sum_month ) ;
    printf( " Bath\n" ) ;

    *sum_month *= 12 ;
    printf( "All salary per year: " ) ;
    sort( sum_month ) ;
    printf( " Bath\n" ) ;

    *sum_month *= 0.07 ;
    printf( "Tax (7%% per year) : " ) ;
    sort( sum_month ) ;
    printf( " Bath\n" ) ;

    *most_salary *= 12 * 0.07 ;
    printf( "Most tax in company : %s (" , Most_name ) ;
    sort( most_salary ) ;
    printf( " Bath per year)\n" ) ;
}//end display

void sort ( float *data ) {
    char Convert[ 100 ] ;
    sprintf( Convert , "%.2f" , *data ) ;
    int length = strlen( Convert ) ; //วัดความยาว
    for ( int i = 0 ; i < length - 3 ; i++ ) { //กำหนดว่าจะพิมกี่ตัว
        if ( i != 0 && ( length - i ) % 3 == 0 ) { //กำหนดว่าถ้าครบ 3 ตัวให้พิม ,
            printf( "," ) ;
        }//end if
        printf( "%c" , Convert[ i ] ) ; 
    }//end for
    printf( "%s" , strchr( Convert, '.' ) ) ; //พิมข้อความทั้งหมดหลังจากทศนิยม
}//end sort

/*
    ผู้บริหารต้องการวิเคราะห์พัฒนาการของพนักงานในบริษัทและศักยภาพของพนักงานจากทักษะที่พัฒนาขึ้นของแต่ละคน ซึ่งแปลงค่าความสามารถของแต่ละคนออกมาเป็นค่า EXP โดยแบ่งอัตราการขึ้นเงินเดือนของแต่ละคนดังนี้
    EXP อยู่ในช่วง 0-1,000 		จะได้รับเงินเดือน x1
	EXP อยู่ในช่วง 1,000-2,000 	จะได้รับเงินเดือน x1.2
	EXP อยู่ในช่วง 2,000-3,000 	จะได้รับเงินเดือน x1.4
	EXP อยู่ในช่วง 3,000-4,000 	จะได้รับเงินเดือน x1.6
	EXP อยู่ในช่วง 4,000-5,000 	จะได้รับเงินเดือน x1.8
	EXP อยู่ในช่วง 5,000 ขึ้นไป	จะได้รับเงินเดือน x2
    โดยผู้บริหารมอบหมายให้ HR เป็นคนกรอกข้อมูลพนักงานในบริษัทและประเมินค่า EXP ของพนักงานแต่ละคน พร้อมสรุปจำนวนคนที่ได้รับเงินเดือนในแต่ละขั้น และระบุคนชื่อคนที่ได้เงินเดือนเยอะที่สุด และคนที่เงินเดือนน้อยที่สุด (หากกรอกเลข -1 ในช่อง Name จะถือเป็นการหยุดโปรแกรมและเตรียมแสดงผล)
    
    Test case:
        Employee 1 Name : 
            Atom
        EXP : 
            2500
        Employee 2 Name : 
            Aom
        EXP : 
            3230
        Employee 3 Name : 
            Aim
        EXP : 
            4560
        Employee 4 Name : 
            Jom
        EXP : 
            5505
        Employee 5 Name : 
            On
        EXP : 
            950
        Employee 6 Name : 
            Oom
        EXP : 
            3500
        Employee 7 Name : 
            Ky
        EXP : 
            2600
        Employee  Name : 
            -1
    Output:
        **** Salary Result ****
        x1.0 count 1
        x1.2 count 0
        x1.4 count 2
        x1.6 count 2
        x1.8 count 1
        x2.0 count 1
        The Employee get x2.0 is Jom
        The Employee get x1.0 is On

    Test case:
        Employee 1 Name : 
            Aey
        EXP : 
            9956
        Employee 2 Name : 
            J
        EXP : 
            4900
        Employee 3 Name : 
            A
        EXP : 
            4560
        Employee 4 Name : 
            Orio
        EXP : 
            200
        Employee 5 Name : 
            Vistra
        EXP : 
            1656
        Employee 6 Name : 
            Oh
        EXP : 
            2300
        Employee  Name : 
            -1
    Output:
        **** Salary Result ****
        x1.0 count 1
        x1.2 count 1
        x1.4 count 1
        x1.6 count 0
        x1.8 count 2
        x2.0 count 1
        The Employee get x2.0 is Aey
        The Employee get x1.0 is Orio
*/
#include <stdio.h>
#include <string.h>

struct Person {
	char  Name[20] ;
    int Exp ;
} ;

struct Person User[ 100 ] ;
char LessName[50] , MostName[50] , LessExp[50] , MostExp[50] ;
char Expx[][ 5 ] = { "x1.0" , "x1.2" , "x1.4" , "x1.6" , "x1.8" , "x2.0" } ;
int i = 0 , count[ 100 ] , MostCompare = -9999 , LessCompare = 9999;

void sort( int Xp ) ;
void display( ) ;

int main () {
    while ( 1 ) {
        printf( "Employee [%d] Name : " , i + 1 ) ;
        scanf( "%s" , User[ i ].Name ) ;
        if ( strcmp( User[i].Name , "-1" ) == 0 ) {
            break ;
        }//end if ถ้ากรอก -1
        printf( "Exp : " ) ;
        scanf( "%d" , &User[ i ].Exp ) ;
        printf( "------------------------\n" ) ;
        sort( User[ i ].Exp ) ;
        i++ ;
    }//end while
    display() ;
    return 0 ;
}//end main

void sort( int Xp ) {
    int j = ( Xp / 1000 ) ;
    if ( j <= 0 ) {
        j = 0 ;
    }else if ( j >= 6 ) {
        j = 5 ;
    }//end if ถ้ามากกว่า 5000
    count[ j ] ++ ;  // เพิ่มจำนวนในช่วงนั้น
    if ( Xp >= MostCompare ) {
        MostCompare = Xp ;
        strcpy( MostExp , Expx[ j ] ) ;
        strcpy( MostName , User[ i ].Name) ;
    }//end if xp มากสึด
    if ( Xp <= LessCompare ) {
        LessCompare = Xp ;
        strcpy( LessExp, Expx[ j ] ) ;
        strcpy( LessName, User[ i ].Name ) ;
    }//end if xp น้อยสุด
}//end sort

void display() {
    printf( " Output:\n**** Salary Result ****\n" ) ;
    for (int j = 0; j < 6; j++) {
        printf("%s count %d\n", Expx[j], count[j]);
    }//end print x..
    printf("\nThe Employee get %s is %s\n", MostExp, MostName);
    printf("The Employee get %s is %s\n", LessExp, LessName);
}//end display

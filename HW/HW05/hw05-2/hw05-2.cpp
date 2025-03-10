/*
    จงเรียงลำดับเลขจากข้อมูลที่ผู้ใช้กรอก โดยเรียงจากมากไปน้อย (โดยใช้คำสั่ง if else หรือ else if เท่านั้น)
    
    Test case:
        Input[1] :
            6
        Input[2] :
            9
        Input[3] :
            1
    Output:
        9 6 1

    Test case:
        Input[1] :
            65
        Input[2] :
            91
        Input[3] :
            112
    Output:
        112 91 65
*/

#include <stdio.h>

int main() {
    int num1 = 0 , num2 = 0 , num3 = 0 ;

    printf( "Input[1] : \n" ) ;
    scanf( "%d" , &num1 ) ;
    
    printf( "Input[2] : \n" ) ;
    scanf( "%d" , &num2 ) ;
    
    printf( "Input[3] : \n" ) ;
    scanf( "%d" , &num3 ) ;

    printf( "\nOutput:\n" ) ;
    if ( num1 >= num2 && num1 >= num3 ) {
        if (num2 >= num3) {
            printf( "%d %d %d" , num1 , num2 , num3 ) ;
        } else {
            printf( "%d %d %d" , num1 , num3 , num2 ) ;
        }//end else
    }//end if หาว่า num1 มากที่สุด
    
    if ( num2 >= num1 && num2 >= num3 ) {
            if (num1 >= num3) {
                printf( "%d %d %d" , num2 , num1 , num3 ) ;
            } else {
                printf( "%d %d %d" , num2 , num3 , num1 ) ;
            }//end else
    }//end if หาว่า num2 มากที่สุด

    if ( num3 >= num1 && num3 >= num2 ) {
        if (num1 >= num2) {
            printf( "%d %d %d" , num3 , num1 , num2 ) ;
        } else {
            printf( "%d %d %d" , num3 , num2 , num1 ) ;
        }//end else
    }//end if หาว่า num2 มากที่สุด
    
    return 0 ;
}//end funtion

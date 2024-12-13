/*
    จงเขียนโปรแกรมเพื่อถอดรหัสข้อมูลจากไฟล์ และแปลงเป็นภาษาอังกฤษให้ถูกต้อง โดยโค๊ดที่อ่านได้จากไฟล์คือภาษาอังกฤษที่ถูกเลื่อนไปทางขวา 6 ตัวอักษร (เข้าไปที่เว็บไซท์นี้ https://studio.code.org/s/hoc-encryption/stage/1/puzzle/1 และทำการเลื่อนตัวอักษรไปทางขวา 6 ครั้ง จะได้รหัสลับนี้มา
    ดูวีดีโอประกอบได้ที่ลิงค์นี้ https://www.youtube.com/watch?v=eN4coe9KKzE

    ข้อมูลภายในไฟล์ a15-9.txt :
        C UG ALIIN
    Output:
        Output: I AM GROOT
*/

#include <stdio.h>

void convert ( int ASCII , char ch ) ;

int main () {
    FILE *fp ;
    fp = fopen( "a15-9.txt" , "r" ) ;
    if ( fp == NULL ) {
        printf("ERR") ;
        return 0 ;
    }//end if err

    char ch ;
    int ASCII = 0 ;
    while ( ( ch = fgetc(f p ) ) != EOF ) {
        ASCII = ch ;
        //printf( "%c" , ch ) ;
        convert( ASCII , ch ) ;
    } // end while
    fclose( fp ) ;
    return 0 ;
}//end main

void convert ( int ASCII , char ch ) {
    if ( ch != ' ' ) {
        ASCII += 6 ;
        if ( ASCII > 90 ) {
            ASCII -= 26 ;
        }//end if ถ้าเกินตัว Z
        printf( "%c" , ASCII ) ;
    } else {
        printf( "%c" , ch ) ;
    }//end if ต้องไม่เป็นช่องว่าง
}//end convert


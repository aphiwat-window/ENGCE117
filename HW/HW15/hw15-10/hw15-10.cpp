#include <stdio.h>

void SCAN ( FILE *fp , int Matrix3[ 100 ] , int *row , int *col ) ;
void Convert( int Matrix[ 100 ][ 100 ] , int Matrixdata[ 100 ] , int row , int col ) ;
void multiply ( int row , int row2 , int col , int col2 , int Matrix1[ 100 ][ 100 ] , int Matrix2[ 100 ][ 100 ] ) ;

int main () {
    FILE *fp ;
    FILE *fp2 ;
    fp = fopen( "a15-10.txt" , "r" ) ;
    fp2 = fopen( "b15-10.txt" , "r" ) ;
    if ( fp == NULL || fp2 == NULL ) {
        printf( "ERR" ) ;
        return 0 ;
    }//end if err

    int Matrix3[ 100 ] , Matrix1[ 100 ][ 100 ] , Matrix2[ 100 ][ 100 ] ;
    int n = 0 , n2 = 0; 
    int col = 0 , col2 = 0;

    printf( "Output:\n" ) ;
    printf( "Matrix A from file1 =:\n" ) ;
    SCAN( fp , Matrix3 , &n , &col) ;
    fclose( fp ) ;
    Convert ( Matrix1 , Matrix3 , n , col ) ;

    printf( "Matrix B from file2 =\n" ) ;
    SCAN( fp2 , Matrix3 , &n2 , &col2 ) ;
    fclose( fp2 ) ;
    Convert ( Matrix2 , Matrix3  , n2 , col2 ) ;

    printf( "Result of A x B =\n" );
    multiply( n , n2 , col , col2 , Matrix1 , Matrix2 ) ;
    return 0 ;  
}//end main


void SCAN ( FILE *fp , int Matrix3[ 100 ] , int *row , int *col ) {
    int num = 0 , j = 0 ; 
    char ch ;
    while (( ch = fgetc(fp)) != EOF ) {
        if (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch - '0') ;  // รวมตัวเลข
        } else if ( ch == '\n' || ch == ' ' || ch == '\t' ) {
            if ( ch == '\n') {
                (*row)++ ;
                (*col) = 0 ;
            }//end if ถ้าเจอวรรบรรทัด
            if ( num != 0 ) {
                //printf("%d ", num) ;
                Matrix3[ j ] = num ;
                j++ ;
                (*col) ++ ;
            }//end ต้องไม่ใช่ 0
            num = 0; ;
        }//end เจอเวรรวัคหรือไม่
    }//end while scan file
    Matrix3[ j ] = num ;
    j++ ;
}//end SCAN

void Convert( int Matrix[ 100 ][ 100 ] , int Matrixdata[ 100 ] , int row , int col ) {
    int j = 0 ;
    for (int i = 0; i < row; i++){
        for ( int k = 0 ; k < col ; k++ ) {
            Matrix[ i ][ k ] = Matrixdata[ j ] ; 
            printf( "%d " , Matrix[ i ][ k ]  ) ;
            j++ ;
        }//end for เอา Matrix 1 มิติใส่ Matrix 2 มิติ
        printf( "\n" ) ;
    }//end for row
    printf( "\n" ) ;
}//end Convert

void multiply ( int row , int row2 , int col , int col2 , int Matrix1[ 100 ][ 100 ] , int Matrix2[ 100 ][ 100 ] ) {
    int Matrix4[ 100 ][ 100 ] ;
    for( int i = 0 ; i < row ; i++ ) {
        for( int j = 0 ; j < col2 ; j++ ) {
            for( int k = 0 ; k < col ; k++ ) {
                Matrix4[i][j] += Matrix1[i][k] * Matrix2[k][j] ;
            }//end for calculator
        }//end for columns
    }//end for rows
    for( int i = 0 ; i < row ; i++) {
        for( int j = 0 ; j < col2 ; j++ ) {
            printf( "%d " , Matrix4[i][j] ) ;
        }
        printf( "\n" ) ;
    }//end for
}//end multiply

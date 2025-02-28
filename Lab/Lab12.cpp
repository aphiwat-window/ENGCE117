#include <stdio.h>

int *KnapsackKP( int *w, int *v, int n, int wx ) ;

int main() {
    int wx = 11, ans = 0, n, i ;
    n = 5 ;
    
    printf( "Enter n : " ) ;
    scanf( "%d", &n ) ;
    printf( "Enter wx : " ) ;
    scanf( "%d", &wx ) ;
    
    int *w = new int[ n ] ;
    int *v = new int[ n ] ;
    for( i = 0 ; i < n ; i++ ) {
        printf( "weight for item %d : ", i ) ;
        scanf( "%d", &w[ i ] ) ;
    }
    for( i = 0 ; i < n ; i++ ) {
        printf( "value for item %d : ", i ) ;
        scanf( "%d", &v[ i ] ) ;
    }
    
    int *x = KnapsackKP( w, v, n, wx ) ;
    for( int i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
    for( int i = 0 ; i < n ; i++ ) if( x[ i ] == 1 ) ans += v[ i ] ;
    printf( "\nValue = %d", ans ) ;
    return 0 ;
}

int *KnapsackKP(int *w, int *v, int n, int wx) {
    int u[n][wx + 1];  
    int y[n][wx + 1];  

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= wx; j++) {
            int a, b;
            if (i - 1 < 0) {
                a = 0;
                y[i][j] = 0;
            } else {
                a = u[i - 1][j];
                y[i][j] = y[i - 1][j];
            }

            if (j - w[i] < 0) {
                b = -1;  
            } else if (j - w[i] == 0 || i - 1 < 0) {
                b = v[i];
            } else {
                b = u[i - 1][j - w[i]] + v[i];
            }

            if (a > b) {
                u[i][j] = a;
            } else {
                u[i][j] = b;
                y[i][j] = y[i - 1][j - w[i]] | (1 << i);
            }
        }

    static int x[100];  
    for (int i = 0; i < n; i++)
        x[i] = (y[n - 1][wx] & (1 << i)) ? 1 : 0;

    return x;
}

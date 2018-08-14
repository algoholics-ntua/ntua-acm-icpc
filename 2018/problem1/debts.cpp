#include <cstdio>
#include <algorithm>
#include <vector>

#define MAXN 10100

#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;

int N, M, minim[ MAXN + 1 ], money[ MAXN + 1 ];

typedef pair< int, int > pii;
typedef pair< pii, pii > payment;
vector< payment > pays;

int main( void ) {
    scanf("%d%d", &N, &M );
    for( int i = 1; i <= M; i++ ) {
        int p, t1, x1, t2, x2;
        scanf("%d%d%d%d%d", &p, &x1, &t1, &x2, &t2 );
        pays.pb( mp( mp( t1, 1 ), mp( x1, p ) ) );
        pays.pb( mp( mp( t2, -1 ), mp( x2, p ) ) );
    }
    sort( pays.begin(), pays.end() );
    for( int i = 0; i < pays.size(); i++ ) {
        payment A = pays[ i ];
        int bank = A.Y.X;
        int value = A.Y.Y;
        int kind = A.X.Y;
        if( kind == 1 ) {
            money[ bank ] -= value;
        } else {
            money[ bank ] += value;
        }
        minim[ bank ] = min( minim[ bank ], money[ bank ] );
    }
    printf("%d", -minim[ 1 ] );
    for( int i = 2; i <= N; i++ ) {
        printf(" %d", -minim[ i ] );
    }
    printf("\n");
    return 0;
}

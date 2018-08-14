#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define MAXN 155
#define MAXV 510

#define INF 1234567890.0

#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair< int, int > pii;
typedef pair< double, pii > node;

double dist[ MAXN + 1 ][ MAXV + 1 ];

int N, M;
pii choice[ MAXN + 1 ][ MAXV + 1 ];
vector< node > G[ MAXN + 1 ];

int readint() {
    int n = 0;
    char c = getchar_unlocked();
    while ( !( '0' <= c && c <= '9' ) ) {
        c = getchar_unlocked();
    }
    while ( '0' <= c && c <= '9' ) {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    return n;
}

void init() {
    for( int i = 0; i <= MAXN; i++ ) {
        for( int j = 0; j <= MAXV; j++ ) {
            dist[ i ][ j ] = INF;
        }
    }
}

void dijkstra( int s ) {
    init();
    priority_queue< node, vector<node>, greater<node> > Q;
    dist[ s ][ 70 ] = 0.0;
    choice[ s ][ 70 ] = mp( 0, 70 );
    Q.push( mp( 0, mp( 0, 70 ) ) );
    while( !Q.empty() ) {
        node A = Q.top();
        Q.pop();
        int u = A.Y.X, vel1 = A.Y.Y;
        double d = A.X;
        for( int i = 0; i < G[ u ].size(); i++ ) {
            int v = G[ u ][ i ].Y.X, vlim = G[ u ][ i ].Y.Y, myvel;
            double l = G[ u ][ i ].X, ans;
            if( vlim == 0 ) {
                myvel = vel1;
            } else {
                myvel = vlim;
            }
            ans = d + ( double )( ( double )l / ( double )myvel );
            if( ans < dist[ v ][ myvel ] ) {
                dist[ v ][ myvel ] = ans;
                choice[ v ][ myvel ] = mp( u, vel1 );
                Q.push( mp( ans, mp( v, myvel ) ) );
            }
        }
    }
}

int main( void ) {
    int D;
    scanf("%d%d%d", &N, &M, &D );
    for( int i = 0; i < M; i++ ) {
        int a, b, l, v;
        scanf("%d%d%d%d", &a, &b, &v, &l );
        G[ a ].pb( mp( ( double )l, mp( b, v ) ) );
    }
    dijkstra( 0 );
    double ans = INF;
    int vel;
    for( int i = 0; i <= MAXV; i++ ) {
        if( dist[ D ][ i ] < ans ) {
            ans = dist[ D ][ i ];
            vel = i;
        }
    }
    int t = D;
    vector< int > path;
    path.pb( t );
    while( t > 0 ) {
        pii u = choice[ t ][ vel ];
        path.pb( u.X );
        t = u.X;
        vel = u.Y;
    }
    printf("%d", path[ path.size() - 1 ] );
    for( int i = path.size() - 2; i >= 0; i-- ) {
        printf(" %d", path[ i ] );
    }
    printf("\n");
    return 0;
}

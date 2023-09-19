#include<bits/stdc++.h>
using namespace std ;
inline int read(){
	int s=0,w=1 ; char g=getchar() ; while( g>'9' || g<'0' ){ if( g=='-')w=-1; g=getchar() ; }
	while( g>='0' && g<='9' )s=s*10+g-'0',g=getchar() ; return s*w ; 
}
#define ll long long
const int MAXN = 100005 ; 
const ll mod = 998244353 ; 
string s ; 
ll a[MAXN] , dp[4][64][10] ;
inline ll add( ll x , ll y ){
	return (x+y+mod)%mod ; 
}
inline int trans( char g ){
	if( g >='0' && g <='9' )return (int)(g-'0') ; 
	if( g >='a' && g <='z' )return (int)(g-'a'+10) ; 
	if( g >='A' && g <='Z' )return (int)(g-'A'+36) ;
	else return -1 ; 
}
inline int kind( int x ){
	if( x == -1 )return -1 ; 
	if( x >= 0 && x <= 9 )return 4  ;
	if( x >= 10 && x < 36 )return 2 ; 
	return 1 ; 
}
void prework(){
	if( a[1] == -1 ){
		for( int i = 0 ; i <= 61 ; ++i )dp[1][i][kind(i)] = 1 ; 
		return ; 
	}
	if( a[1] >= 0 && a[1] <= 9 ){
		dp[1][a[1]][4] = 1 ; return ; 
	}
	if( a[1] >= 10 && a[1] < 36 ){
		dp[1][a[1]][2] = dp[1][a[1]+26][1] =1 ; return ; 
	}
	if( a[1] >= 36 ){
		dp[1][a[1]][1] = 1 ; return ; 
	}
}
int main(){
	ios::sync_with_stdio(false) ; 
	int n ; cin>>n ;  cin>>s ; 
	for( int i = 0 ; i < n ; ++i )
		a[i+1] = trans(s[i]) ; 
	prework() ; 
	for( int i = 2 ; i <= n ; ++i ){
		for( int j = 0 ; j <= 61 ; ++j )
			for( int k = 0 ; k <= 7 ; ++k )dp[i&1][j][k] = 0 ;
		int ka = kind( a[i] ) ; 
		if( ka == -1 ){ // ?
			ll tmp[8] = { 0,0,0,0,0,0,0,0} ; 
			for( int k = 0 ; k <= 7 ; ++k )
				for( int y = 0 ; y <= 61 ; ++y )
					tmp[k] += dp[(i-1)&1][y][k] , tmp[k] %= mod;
			for( int x = 0 ; x <= 61 ; ++x ){
				for( int k = 0 ; k <= 7 ; ++k )
					if( k&kind(x)  ){
						dp[i&1][x][k] = add( tmp[k-kind(x)] , tmp[k] );
						dp[i&1][x][k] = add( dp[i&1][x][k] , -dp[(i-1)&1][x][k] );
						dp[i&1][x][k] = add( dp[i&1][x][k] , -dp[(i-1)&1][x][k-kind(x)] );
					}
			}
		}
		else if( ka == 4 ){// number
			for( int x = a[i] ; x <= a[i] ; ++x ){
				for( int k = 0 ; k <= 7 ; ++k )
					if( k&kind(x) )
					for( int y = 0 ; y <= 61 ; ++y ){
						if( y == x )continue ; 
						dp[i&1][x][k] = add( dp[i&1][x][k] , dp[(i-1)&1][y][k] );
						dp[i&1][x][k] = add( dp[i&1][x][k] , dp[(i-1)&1][y][k-kind(x)] );
					}
			}
		} 
		else if( ka == 1 ){ // upper
			for( int x = a[i] ; x <= a[i] ; ++x ){
				for( int k = 0 ; k <= 7 ; ++k )
					if( k&kind(x) )
					for( int y = 0 ; y <= 61 ; ++y ){
						if( y == x )continue ; 
						dp[i&1][x][k] = add( dp[i&1][x][k] , dp[(i-1)&1][y][k] );
						dp[i&1][x][k] = add( dp[i&1][x][k] , dp[(i-1)&1][y][k-kind(x)] );
					}
			}
		}
		else if( ka == 2 ){ // lower
			for( int x = a[i] ; x <= 61 ; x += 26 ){
				for( int k = 0 ; k <= 7 ; ++k )
					if( k&kind(x) )
					for( int y = 0 ; y <= 61 ; ++y ){
						if( y == x )continue ; 
						dp[i&1][x][k] = add( dp[i&1][x][k] , dp[(i-1)&1][y][k] );
						dp[i&1][x][k] = add( dp[i&1][x][k] , dp[(i-1)&1][y][k-kind(x)] );
					}
			}
		}
	}
	ll ans = 0 ;
	for( int i = 0 ; i <= 61 ; ++i )ans = add( ans , dp[n&1][i][7] ) ; 
	cout<<ans%mod  ;
}

#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b) { return (a > b ? a : b);}
int min(int a,int b) { return (a < b ? a : b);}

const int N = 1e6 + 10;

void solve(){
    int n; cin>>n; n /= 1000;
    int ds = 24 * 60 * 60;
    n %= ds;
    int h = n / 3600, m = n % 3600 / 60, s = n % 60;
    printf("%02d:%02d:%02d\n", h, m ,s); 
}

signed main(){
    solve();
    return 0;
}

/*
46800999
13:00:00

1618708103123
01:08:23
*/

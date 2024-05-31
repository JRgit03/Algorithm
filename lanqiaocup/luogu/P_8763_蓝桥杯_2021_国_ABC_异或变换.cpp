#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e4 + 10, up = 1e5;
int n,t;
int a[2][N];

// AC 40/100
void solve1(){
    for(int i=1;i<=t;i++){
        int cur = i & 1, pre = cur ^ 1;
        for(int j=1;j<=n;j++){
            if(j == 1) a[cur][j] = a[pre][j];
            else a[cur][j] = a[pre][j - 1] ^ a[pre][j]; 
        }
    }
    for(int i=1;i<=n;i++) cout << a[t & 1][i];
}

void solve(){
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        char c; cin>>c; a[0][i] = c - '0'; 
    }
    // if(n * t <= up) solve1();
    for(int i=1;i<=t;i++){
        int cur = i & 1, pre = cur ^ 1;
        for(int j=1;j<=n;j++){
            if(j == 1) a[cur][j] = a[pre][j];
            else a[cur][j] = a[pre][j - 1] ^ a[pre][j]; 
        }
        for(int i=1;i<=n;i++) cout << a[cur][i]; cout << "\n";
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}

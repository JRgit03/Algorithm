#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e6 + 10, maxn = 1e6;
int n;
int g[N];


// 对于数i来说会衍生出G[i]段长度为i的数 i * g[i]
void solve(){
    g[1] = 1; g[2] = 2;
    for(int i=2,j=2;i<=maxn;i++){
        for(int k=0;k<g[i]&&j<=maxn;k++) g[j++] = i;
    }    
    cin>>n;
    int s = 0,t = 0; // s当前枚举到的值 t当前指向的数
    for(int i=1;;i++){
        s += i * g[i];
        if(s >= n){
            s -= i * g[i];
            cout << t + (n - s + i - 1) / i << "\n";
            break;
        }
        t += g[i];
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}

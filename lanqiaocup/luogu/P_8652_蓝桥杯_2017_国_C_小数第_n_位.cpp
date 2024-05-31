#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e6 + 10;
int a,b,n;

int fastpow(int a,int b,int mod){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}


// a/b的第n位小数 => (a * 10 ^ n / b) % 10
// 求第n位小数 先求n-1的余数 再 * 10 / b % 10;  *10相等于补0
void solve(){
    cin>>a>>b>>n;
    cout << a * fastpow(10, n-1, b) * 10 / b % 10;
    cout << a * fastpow(10, n  , b) * 10 / b % 10;
    cout << a * fastpow(10, n+1, b) * 10 / b % 10;
}

signed main(){
    IOS;
    solve();
    return 0;
}

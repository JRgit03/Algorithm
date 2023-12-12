#include <bits/stdc++.h>
#define int long long
using namespace std;
int a,b,p;

// a * b 对b二进制分解 3 * 7 = 3 * (1 + 2 + 4)
int slowmul(int a,int b,int p){
    int res = 0;
    while(b){
        if(b & 1) res = (res + a) % p;
        b >>= 1;
        a = 2 * a % p;
    }
    return res % p;
}

signed main(){
    cin>>a>>b>>p;
    cout << slowmul(a,b,p) << "\n";
    return 0;
}

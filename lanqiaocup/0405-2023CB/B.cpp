#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define int long long
using namespace std;

void solve(){
    double t = 11625907.5798;
    int n = 23333333;
    for(int i=0;i<=n;i++){
        double x = i, y = n - i;
        if(x >= y) break;
        double res = - x * x / (x + y) * log2(x / (x + y)) - y * y / (x + y) * log2(y / (x + y));
        if(fabs(res - t) <= 0.0001){
            cout << i << "\n"; // 11027421
        }
    } 
}

signed main(){
    IOS; solve();
    return 0;
} 


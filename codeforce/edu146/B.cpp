#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
void solve(){
    int a,b;cin>>a>>b;
    int res = a+b;
    for(int i=1;i<=100000;i++){
        res = min(res,(a+i-1)/i + (b+i-1)/i + i-1);
    }
    cout << res << "\n";
}

int main(){
    int t;cin>>t;while(t--)solve();
    return 0;
}

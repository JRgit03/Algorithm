#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n;
int a[N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int sz = 1, sum = 1, cnt0 = 0; 
    for(int i=1;i<=n;i++){
        if(a[i] == 1) sum++,sz++;
        else if(a[i] == 0){
            if(sz >= 2) sz--,cnt0++;
            else sum++,sz++;
        }else if(a[i] == -1){
            if(sz >= 2) sz--;
            else if(cnt0 >= 1) sum++,sz++,cnt0--; //反悔
            else {
                cout << -1 << "\n";
                return;
            }
        }
    }
    cout << sum / __gcd(sum,sz) << " " << sz / __gcd(sum,sz) << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}

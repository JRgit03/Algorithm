#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 10;
int n;
int x[N],l[N];

int check(int up){
    int l = 1, r = 1;
    for(int i=1;i<=n;i++){
        int c = x[i] - x[i-1];
        r += c;
           
    }
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>l[i];
    x[0] = 0, l[0] = 1;
    for(int i=1;i<=n;i++) l[i] = min(l[i], l[i-1] + x[i] - x[i-1]);
    int l = 1, r = 1e10;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }    
    cout << r << "\n";
}

signed main(){
    solve();
    return 0;
}

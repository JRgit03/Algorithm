#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int n,m;
int a[N];
int b[N];

void add(int l,int r){
    b[l] += 1; b[r+1] -= 1;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    while(m--){
        int l,r; cin>>l>>r;
        add(l,r);
    } 
    int s1 = 0, s2 = 0;
    for(int i=1;i<=n;i++) {
        b[i] += b[i-1];
        s1 += b[i] * a[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for(int i=1;i<=n;i++) s2 += a[i] * b[i];
    cout << s2 - s2 << "\n";
}

signed main(){
    solve();
    return 0;
}

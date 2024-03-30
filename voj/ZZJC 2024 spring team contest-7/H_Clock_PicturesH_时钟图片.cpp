#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, P = 131, P2 = 1e9 + 7;
int n;
int a[N],b[N];
int c[N],d[N];

typedef unsigned long long ULL;
ULL h[N],h2[N],p[N];
ULL h3[N],h4[N],p2[N];

ULL gethash(int l,int r,ULL h[]){
    return h[r] - h[l-1] * p[r-l+1];
}

ULL gethash3(int l,int r,ULL h[]){
    return h[r] - h[l-1] * p2[r-l+1];
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]; 
    for(int i=1;i<=n;i++) cin>>b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    a[0] = a[n], b[0] = b[n];
    for(int i=1;i<=n;i++) c[i] = (a[i] - a[i-1] + 360000) % 360000;
    for(int i=1;i<=n;i++) d[i] = (b[i] - b[i-1] + 360000) % 360000;
    // for(int i=1;i<=n;i++) printf("c[%d] = %d\n", i, c[i]); cout << "\n";
    // for(int i=1;i<=n;i++) printf("d[%d] = %d\n", i, d[i]); cout << "\n";
    p[0] = p2[0] = 1;
    for(int i=1;i<=n;i++){
        h[i] = h[i-1] * P + c[i];
        h2[i] = h2[i-1] * P + d[i];
        p[i] = p[i-1] * P;

        h3[i] = h3[i-1] * P2 + c[i];
        h4[i] = h4[i-1] * P2 + d[i];
        p2[i] = p2[i-1] * P2;
    }
    // int suc = (gethash(1,n,h) == gethash(1,n,h2) && gethash3(1,n,h3) == gethash3(1,n,h4));
    int suc = (gethash3(1,n,h3) == gethash3(1,n,h4));
    for(int l=n,r=n;l>=1;l--){
        ULL hash1 = gethash(1,n,h);
        ULL hash2 = gethash(l,r,h2) * p[l - 1] + gethash(1,l-1,h2);

        ULL hash3 = gethash3(1,n,h3);
        ULL hash4 = gethash3(l,r,h4) * p2[l - 1] + gethash3(1,l-1,h4);
        
        // cout << hash1 << " " << hash2 << "\n";
        // cout << hash3 << " " << hash4 << "\n"; cout << "\n";
        if( hash3 == hash4) suc = 1;
    }

    cout << (suc ? "possible" : "impossible") << "\n";
}

signed main(){
    solve();
    return 0;
}

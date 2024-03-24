#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, P = 13331;
string s1,s2;
typedef unsigned long long ULL;
ULL h[N],h2[N],p[N];

ULL gethash(int l,int r,ULL h[]){
    return h[r] - h[l-1] * p[r - l + 1];
}

void init(){
    s1 = "?" + s1;
    s2 = "?" + s2; 
    p[0] = 1;
    for(int i=1;i<=s1.length()-1;i++){
        h[i] = h[i-1] * P + s1[i];
        p[i] = p[i-1] * P;
    }
    for(int i=1;i<=s2.length()-1;i++){
        h2[i] = h2[i-1] * P + s2[i];
        p[i] = p[i-1] * P;
    }
}

void solve(){
    cin>>s1>>s2;
    int n = s1.length(), m = s2.length();
    init();
    int ans = 0;
    for(int i=1;i+n-1<=m;i++){
        int l = i, r = i + n - 1;
        if(gethash(1,n,h) == gethash(l,r,h2)) ans += 1;
    }
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}

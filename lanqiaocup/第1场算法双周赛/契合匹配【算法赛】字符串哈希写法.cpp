#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10 , P = 131;
int n,m;
string s,t;
typedef unsigned long long ULL;
ULL h[N<<1],p[N<<1];
ULL hh[N];

ULL gethash(int l,int r){
    return h[r] - h[l-1] * p[r-l+1];
}

int main(){
    cin>>n; m = n;
    cin>>s>>t; n <<= 1;
    p[0] = 1;
    s = "?" + s + s;
    for(int i=1;i<=n;i++) p[i] = p[i-1] * P;
    for(int i=1;i<=n;i++) {
        s[i] = (islower(s[i]) ? toupper(s[i]) : tolower(s[i]));
        h[i] = h[i-1] * P + s[i];
    }
    t = "?" + t;
    for(int i=1;i<=m;i++) hh[i] = hh[i-1] * P + t[i];
    ULL tar = hh[m];
    int ans = INT_MAX;
    for(int i=1;i<=m;i++){
        if(gethash(i,i+m-1) == tar){;
            ans = min({ans,i-1,m-(i-1)});
        }
    }
    if(ans == INT_MAX){
        cout << "No" << "\n";
        return 0;
    }
    cout << "Yes" << "\n";
    cout << ans << "\n";
    return 0;
}
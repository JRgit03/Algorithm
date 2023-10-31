#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10 , P = 13331;
int n;
string str;
typedef unsigned long long ULL;
ULL h[N],p[N],rh[N];

ULL gethash(int l,int r){
    return h[r] - h[l-1] * p[r-l+1];
}

ULL getrhash(int l,int r){
    return rh[l] - rh[r+1] * p[r-l+1];
}

void init(){
    int len = str.length();
    str = "?" + str;
    p[0] = 1;
    for(int i=1;i<=len;i++){
        h[i] = h[i-1] * P + str[i];
        rh[n-i+1] = rh[n-i+1+1] * P + str[n-i+1]; 
        p[i] = p[i-1] * P;
    }
}

int main(){
    cin>>str; n = str.length();
    init();
    int t; cin>>t;
    while(t--){
        int a,b,c,d; cin>>a>>b>>c>>d;
        cout << (gethash(a,b) == gethash(c,d) ? "Yes" : "No") << "\n";
    }
    return 0;
}
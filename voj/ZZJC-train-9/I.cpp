#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e6 + 10 , P = 131;
typedef unsigned long long ULL;
int n,q;
char str[N];

ULL h[N],rh[N],p[N];

ULL gethash(int l,int r){  //计算正序哈希值
    return h[r] - h[l-1] * p[r-l+1];
}

ULL getrhash(int l,int r){  //计算逆序哈希值
    return rh[l] - rh[r+1] * p[r-l+1];
}

void init(){
    p[0] = 1;
    for(int i=1;i<=n;i++){
        h[i] = h[i-1] * P + (str[i]-'a');
        rh[n-i+1] = rh[n-i+1+1] * P + (str[n-i+1]-'a');
        p[i] = P * p[i-1];
    }
}

int main(){
    IOS;
    cin>>n>>q>>str+1;
    init();
    while(q--){
        int l,r;cin>>l>>r;
        if((r-l)&1 || gethash(l,r)==getrhash(l,r)) cout << "Budada" << "\n";
        else cout << "Putata" << "\n";
    }
    return 0;
}

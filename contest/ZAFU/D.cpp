#include <bits/stdc++.h>
#define int long long
using namespace std;

int k;

void ask(int u,int v){
    cout << "? " << u << " " << v << "\n";
}

void out(int a,int b){
    cout << "! " << a << " " << b << "\n";
}

void solve(){
    cin>>k;
    if(k==1){
    	out(1,1);return;
	}
    int fa = 1 , sz;
    while(true){
        ask(fa,fa<<1);
        cin>>sz;
        if(sz & 1){
            if(sz==1){
                out(fa,fa<<1);
                return;
            }
            fa = fa << 1;
        }else{
            ask(fa,fa<<1|1);
            cin>>sz;
            if(sz==1){
                out(fa,fa<<1|1);
                return;
            }
            fa = fa << 1 | 1;
        }
    }
}

signed main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}

#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

int f(int x){
    if(!x) return 0;
    if(x>0){
        if(x&1) return 1;
        else{
            if((x/2)%2==1) return 2;
            else return 3;
        }
    }else{
        x = -x;
        if(x%2==0) return 1;
        else return 2;
    }
}

void solve(){
    int a,b;cin>>a>>b;
    int dif = b-a;
    cout << f(dif) << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b; cin>>a>>b;
    int x1,y1,x2,y2;
    x1=y1=x2=y2=0;
    
    if(a == b){
        cout << 0 << "\n";
        return;
    }

    while(a%5==0) a/=5 , x1 += 1;
    while(a%6==0) a/=6 , y1 += 1;
    
    while(b%5==0) b/=5 , x2 += 1;
    while(b%6==0) b/=6 , y2 += 1;

    if(a != b) {
        cout << -1 << "\n";
        return;
    }

    if(x1 > x2 || y1 < y2){
        cout << -1 << "\n";
        return;
    }

    cout << x2 - x1 + y1 - y2 << "\n";
}

int main(){
    int t; cin>>t;
    while(t--)solve();
    return 0;
}

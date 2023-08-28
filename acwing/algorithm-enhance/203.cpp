#include <bits/stdc++.h>
#define int long long
using namespace std;

int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x = 1 , y = 0;
        return a;
    }
    int d = exgcd(b,a%b,y,x);
    y -= (a/b) * x;
    return d;
}

signed main(){
    int a,b;cin>>a>>b;
    int x,y;exgcd(a,b,x,y);
    cout << (x%b+b)%b << "\n";
    return 0;
}

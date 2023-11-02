#include <bits/stdc++.h>
using namespace std;
int a,b,p;

int fastpow(int a,int b,int p){
    int res = 1;
    while(b){
        if(b & 1) res = 1L * res * a % p;
        b >>= 1;
        a = 1LL * a * a % p;
    }
    return res % p;
}

int main(){
    cin>>a>>b>>p;
    cout << fastpow(a,b,p) << "\n";
    return 0;
}

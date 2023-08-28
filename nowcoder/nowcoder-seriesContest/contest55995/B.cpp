#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10 , Mod = 1e9 + 7;
const int Upper = 1e6;
int primes[N] , cnt;
bool st[N];

int sz[N];

int qmi(int a,int b,int p){
    int res = 1 , t = a;
    while(b){
        if(b&1) res = 1LL * res * t % p;
        t = 1LL * t * t % p;
        b >>= 1;
    }
    return res;
}

int main(){
    for(int i=2;i<=Upper;i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j=0;primes[j]<=Upper/i;j++){
            st[primes[j]*i] = true;
            if(i%primes[j]==0) break;
        }
    }   
    for(int i=2;i<=Upper;i++)
        for(int j=i;j<=Upper;j+=i)
            
            sz[j]++;
    int t;cin>>t;
    while(t--){
        int n,c;cin>>n>>c; cout << sz[n] << "\n";
        cout << qmi(c,sz[n],Mod) << "\n";
    }
    return 0;
}

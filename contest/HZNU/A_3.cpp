#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n;
int f[N],g[N]; // f[i]表示比i大的个数 g[i]表示比i小的个数

void add(int b[] , int l , int r){
    b[l] += 1 , b[r+1] -= 1;
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(x-1>=1)add(f,1,x-1);
        if(x+1<=200000)add(g,x+1,200000);
    }
    int res = 0;
    for(int i=1;i<=200000;i++) f[i] += f[i-1] , g[i] += g[i-1];
    for(int i=1;i<=200000;i++)
        if(f[i] == g[i]){
            cout << i << "\n";
            res++;
        }
    return 0;
}

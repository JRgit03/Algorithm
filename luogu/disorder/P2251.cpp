#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10 , M = 21;
int n,m;
int len;
int f[N][M]; //f[i,j]表示以i为起点,2^j为长度 [i,i+2^j-1]
int Log2[N];

int query(int l,int r){
    return min(f[l][len],f[r-(1<<len)+1][len]);
}

int main(){
    cin>>n>>m;len=log2(m);
    for(int i=1;i<=n;i++) cin>>f[i][0];
    for(int j=1;j<M;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f[i][j] = min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    for(int i=1;i<=n-m+1;i++)
        printf("%d\n",query(i,i+m-1));
    return 0;
}

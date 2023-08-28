/**
 * 区间gcd可重复贡献问题 + 满足结合律  --->  ST表 
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1010 , M = 12;
int n,q;
int f[N][M]; // f[i,j]表示维护以i为起点,长度为2^j的区间gcd
int len[N]; // 预处理log2

int gcd(int a,int b){
    return b ? gcd(b,a%b) : a;
}

int query(int l,int r){
    int k = len[r-l+1];
    return gcd(f[l][k],f[r-(1<<k)+1][k]);
}

int main(){
    len[1] = 0;
    for(int i=2;i<N;i++) len[i] = len[i>>1] + 1;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>f[i][0];
    for(int j=1;j<=M;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f[i][j] = gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    while(q--){
        int l,r;cin>>l>>r;
        cout << query(l,r) << "\n";
    }
    return 0;
}

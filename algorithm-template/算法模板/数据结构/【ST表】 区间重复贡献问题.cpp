/**
 * https://www.luogu.com.cn/problem/P3865
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e5 + 10 , logn = 21; // (1<<21) = 2097152
int n,m;
int f[N][logn]; //f[i,j]表示区间[i,i+2^j-1]区间最值  ·以i为起点长度为2^j到区间最值
int Log2[N];    //预处理log2(n) 避免调用库函数 O(logn) -> O(1)查询

int main(){
    IOS; 
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>f[i][0];
    Log2[1] = 0 , Log2[2] = 1;
    for(int i=3;i<N;i++) Log2[i] = Log2[i/2] + 1;
    for(int j=1;j<=logn;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=0;i<m;i++){
        int l,r;cin>>l>>r;
        int len = Log2[r - l + 1];
        cout << max(f[l][len],f[r-(1<<len)+1][len]) << "\n";
    }
    return 0;
}

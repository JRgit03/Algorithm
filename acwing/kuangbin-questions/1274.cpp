#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 5e4 + 10 , M = 17;
int n,m;
int f[N][M],g[N][M]; //f[i,j]表示从i个开始，长度为2^j 的 最大值 g同理最小值
int step[N];

int query(int l,int r){
    int len = step[r-l+1];
    return max(g[l][len],g[r-(1<<len)+1][len]) - min(f[l][len],f[r-(1<<len)+1][len]);
}

int main(){
    IOS;
    cin>>n>>m;
    step[1] = 0;
    step[2] = 1;
    for(int i=3;i<=n;i++) step[i] = step[i/2] + 1;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        f[i][0] = g[i][0] = x;
    }    
    for(int j=1;j<=16;j++)
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
            g[i][j]=max(g[i][j-1],g[i+(1<<(j-1))][j-1]);
        }
    while(m--){
        int l,r;cin>>l>>r;
        cout << query(l,r) << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10 , M = 20;
int n,q;
int f[N][M];
int LOG2[N];

int query(int l,int r){
    int len = LOG2[r-l+1];//cout<<len<<"\n";
    return max(f[l][len],f[r-(1<<len)+1][len]);
}

int main(){
    LOG2[1] = 0; for(int i=2;i<N;i++) LOG2[i] = LOG2[i>>1] + 1;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>f[i][0];
    for(int j=1;j<M;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        cout << query(l,r) << "\n";
    }
    return 0;
}

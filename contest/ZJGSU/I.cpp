#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int maxn;
int res=2e9;

int vis[N];
int path[N];

void dfs(int k){
    if(k==maxn+1){
        int cur = 0;
        for(int i=1;i<=maxn;i++){
            cur += path[i] ^ path[i-1];
        }
        res = min(res , cur);
        if(cur==12 || cur==4){
            for(int i=0;i<=maxn;i++)cout<<path[i]<<" \n"[i==maxn];
        }
    }
    for(int i=0;i<=maxn;i++){
        if(!vis[i]){
            vis[i]=true;
            path[k]=i;
            dfs(k+1);
            vis[i]=false;
        }
    }
}

int main(){
    int n; 
    while(cin>>n){
        res = 2e9;
        cin>>n; maxn = pow(2,n)-1;
        // 0 ~ 2^n-1
        dfs(0);
        cout << res << "\n";
    }
    return 0;
}

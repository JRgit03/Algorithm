#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 11;
int n,x;
bool vis[N];
int path[N];
int king[N];

void dfs(int k){
    if(k==n+1){
        int win = 0;
        for(int i=1;i<=n;i++) win += (path[i]-king[i]>=x);
        if(win > n-win){
            for(int i=1;i<=n;i++)cout<<path[i]<<" \n"[i==n];
        }
        return;           
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            path[k]=i;
            vis[i] = true;
            dfs(k+1);
            vis[i] = false;
        }
    }
}

int main(){
    IOS;
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>king[i];
    dfs(1);
    return 0;
}

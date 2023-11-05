#include <bits/stdc++.h>
using namespace std;
const int maxn = 22;
int n,ans;
int vis[maxn];
int path[maxn];

set<int> st = {2,3,5,7,11,13,17,19};

void dfs(int k,int pre){
    if(k == n+1){
        ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i] && !st.count(i+pre)){
            vis[i] = 1;
            path[k] = i;
            dfs(k+1,i); 
            vis[i] = 0;
        }
    }
}

int main(){
    cin>>n;
    dfs(1,0x3f3f3f3f);
    cout<<ans<<"\n";
    return 0;
}

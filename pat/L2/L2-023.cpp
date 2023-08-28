#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n,m,k;

int color[N];
int vis[N];
vector<int> h[N];

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        h[u].push_back(v);
        h[v].push_back(u);
    }
    int q;cin>>q;
    while(q--){
        set<int> cnt;
        for(int i=1;i<=n;i++){
            int x;cin>>x;x++;
            color[i] = x;  cnt.insert(x);
        }
        if(cnt.size() != k)puts("No");
        else{
            bool flag = true;
            for(int i=1;i<=n;i++){
                for(auto v : h[i]){
                    if(color[v]==color[i]){
                        flag = false;break;
                    }
                }
                if(!flag)break;
            }
            if(flag)puts("Yes");
            else puts("No");
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,m;
int a[N];
vector<int> depth[N]; // depth[i] = {...} 深度为i的点集

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) depth[a[i]].push_back(i);
    int suc = 1;
    for(int i=1;i<=n-1;i++) {
        int sz = depth[i].size(), preSz = depth[i-1].size();
        if(sz > 0 && preSz == 0) suc = 0; 
    }    
    if(!suc) {
        cout << -1 << "\n";
        return;
    }
    int ne = m - (n - 1);
    vector<pair<int,int>> edges;
    for(int i=2;i<=n;i++){
        edges.push_back({i, depth[a[i]-1][0]});   
        // cout << i << " " << a[i] << " " << depth[a[i]-1].size() << "\n";
        for(int j=1;j<depth[a[i]-1].size() && ne > 0;j++){
            edges.push_back({i, depth[a[i]-1][j]});
            ne -= 1;
        }
    }
    // 同一层
    for(int i=1;i<=n-1 && ne > 0;i++) {
        for(int j=1;j<depth[i].size() && ne > 0;j++){
            for(int k=0;k<j && ne > 0;k++){
                edges.push_back({depth[i][k], depth[i][j]});
                ne -= 1;
            }
        }
    } 
    if(ne > 0){
        cout << -1 << "\n";
        return;
    }
    for(auto &[u,v] : edges) cout << u << " " << v << "\n";
    return;
}

int main(){
    solve(); 
    return 0;
}


// 距离为i的点只能连接距离为i / i-1的点 不会改变dist大小

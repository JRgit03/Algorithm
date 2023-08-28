#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int max_depth=-1,res;
vector<int> h[N];

void dfs(int u,int d){
    if(d > max_depth){
        max_depth = d;
        res = u;
    }

    for(auto v : h[u]){
        //cout << u << " " << v << "\n";
        dfs(v,d+1); 
    }
        
}

bool not_root[N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int x;cin>>x;
            not_root[x] = true;
            h[i].push_back(x);
        }
    }
    int root = 1;
    while(not_root[root])root++; //cout<<"root=" << root<<"\n";
    dfs(root,1);
    cout << res << "\n";
    return 0;
}

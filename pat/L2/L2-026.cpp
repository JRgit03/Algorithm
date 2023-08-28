#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,root;

vector<int> h[N];
vector<int> vec[N];
int max_depth = -1;

void dfs(int u,int d){
    if(d > max_depth) max_depth = d;
    
    vec[d].push_back(u);

    for(auto &v : h[u])
        dfs(v,d+1);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int fa;cin>>fa;
        if(fa!=-1)h[fa].push_back(i);
        else root = i;
    }
    dfs(root,1);
    cout << max_depth << "\n";
    cout << vec[max_depth][0];
    for(int i=1;i<vec[max_depth].size();i++) cout << " " << vec[max_depth][i];
    return 0;
}

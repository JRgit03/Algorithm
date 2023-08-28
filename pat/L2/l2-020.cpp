#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
double Z,r;
double res;

vector<int> h[N];
int mul[N];

void dfs(int u,double cur){
    if(mul[u]){
        res += cur * mul[u];
    }
    for(auto v : h[u])
        dfs(v , cur*r);
}

int main(){
    cin>>n>>Z>>r; r = (100.0 - r) / 100.0;
    for(int i=0;i<n;i++){
        int m;cin>>m;
        if(!m){
            int x;cin>>x;mul[i] = x;
        }
        for(int j=0;j<m;j++){
            int x;cin>>x;
            h[i].push_back(x);
        }
    }

    dfs(0,Z);

    printf("%d",(int)res);
    return 0;
}

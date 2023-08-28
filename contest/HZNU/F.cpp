#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int n;
int res;
int sz[N];
vector<PII> h[N];

void dfs(int u,int fa){
    sz[u] = 1;
    for(auto [v,w] : h[u]){
        if(v!=fa){
        	dfs(v,u);
        	sz[u] += sz[v];
        }
    }
}

void bfs(int u,int x){
	res = (n-1) & 1 ? 0 : x;
	queue<pair<int,int>> q;
	q.push({u,-1});
	while(q.size()){
		auto [u,fa] = q.front(); q.pop();
		
		for(auto [v,w] : h[u]){
			if(v!=fa){
				if(sz[v] & 1) res ^= w;
				q.push({v,u});
			}
		}
	}
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        h[u].push_back({v,w});
        h[v].push_back({u,w});
    }
    int q;cin>>q;
    while(q--){
        int u,x;scanf("%d%d",&u,&x);
        dfs(u,-1);
        bfs(u,x);
        printf("%d\n",res);
    }
    return 0;
}

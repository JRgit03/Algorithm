#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long ll;
int n;
int vis[N];
int val[N];
ll dp[N][2];
int father[N];
vector<int> g[N];

void dfs(int u, int st){
	vis[u] = 1; 
	dp[u][0] = 0;
	dp[u][1] = val[u];
	
	for(auto v : g[u]){
		if(v == st) continue;
		dfs(v,st); 
		dp[u][1] += dp[v][0];
		dp[u][0] += max(dp[v][1],dp[v][0]);
	} 
}

int find(int x){
	vis[x] = 1;
	int pre = father[x];
	if(vis[pre]) return pre;
	return find(pre);
}

ll calc(int x){
	ll res = 0;
	int st = find(x);
	dfs(st,st);
	res = max(res, dp[st][0]);
	int st_fa = father[st];
	dfs(st_fa,st_fa);
	res = max(res, dp[st_fa][0]);
	return res;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int fa; scanf("%d%d",&val[i],&fa);
		g[fa].push_back(i); father[i] = fa;
	}
	ll ans = 0;
	for(int i=1;i<=n;i++)
		if(!vis[i])	
			ans += calc(i);
	printf("%lld\n",ans);
	return 0;
}


//2
//10 2
//30 1

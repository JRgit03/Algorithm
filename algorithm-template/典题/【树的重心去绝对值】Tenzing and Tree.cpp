/**
 * 题意：给定n点n-1边的树,其中k个点被染成黑色,每条边的边权为两侧黑点数量的差的绝对值
 *      一棵树的权值是所有边的权值之和, 求确定k个点后树的权值的最大值, 求ans[1~k]
 * 思路：对于k个点的方案，钦定重心为黑点, s[u]表示以u为根的子树黑点数，则
 *       ans[k] = sum(|s[u] - (k - s[u])|) u!=root => k - 2 * s[u] 
 *              => (n - 1) * k + sum(dep[u] - 1) u is black  
*/
const int N = 5e3 + 10;
int n,depth[N],ans[N];
vector<int> g[N];

void dfs(int u,int f){
    for(auto &v : g[u]){
        if(v == f) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){ // 枚举以i为根
        depth[i] = 1;
        dfs(i, i);
        sort(depth + 1, depth + 1 + n);
        int s = 0;
        for(int k=1;k<=n;k++) { // ans[k] 取前k个点
            s += depth[k];
            ans[k] = max(ans[k], (n + 1) * k - 2 * s);
        }
    }
    for(int i=0;i<=n;i++) cout << ans[i] << " "; cout << "\n";
}
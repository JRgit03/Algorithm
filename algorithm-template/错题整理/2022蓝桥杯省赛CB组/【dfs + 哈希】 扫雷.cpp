/*
    题意：给定n个地雷,m个排雷火箭,排雷火箭引爆地雷的条件是 地雷在它的范围内, 地雷也可以引爆地雷
         同一坐标点可能有多个地雷/排雷火箭, 求可以引爆多少地雷！
         n,m <= 5e4, xi,yi <= 1e9, ri <= 10
    思路：可以观察到ri<=10, O(400 * m + 400 * n), 同时地雷位置进行哈希 模拟爆炸 进行dfs爆搜 
*/
const int N = 5e4 + 10, up = 1e9;
int n,m;
int vis[N];
map<pair<int,int>, vector<int>> mp; // {{{x,y},{id1,id2,...}}...}
int x[N],y[N],r[N];

void dfs(int a,int b,int c){
    for(int x=max(0, a-c);x<=min(up, a+c);x++){
        for(int y=max(0,b-c);y<=min(up, b+c);y++){
            if(mp.count({x,y}) && (a - x) * (a - x) + (b - y) * (b - y) <= c * c){
                int maxr = -1;
                for(auto &id : mp[{x,y}]) {
                    maxr = max(maxr, r[id]);
                    vis[id] = 1;
                }
                mp.erase({x,y});
                dfs(x,y,maxr);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>x[i]>>y[i]>>r[i];
        mp[{x[i], y[i]}].push_back(i);
    }
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        for(int x=max(0, a-c);x<=min(up, a+c);x++){
            for(int y=max(0,b-c);y<=min(up, b+c);y++){
                if(mp.count({x,y}) && (a - x) * (a - x) + (b - y) * (b - y) <= c * c){
                    int maxr = -1;
                    for(auto &id : mp[{x,y}]) {
                        maxr = max(maxr, r[id]);
                        vis[id] = 1;
                    }
                    mp.erase({x,y});
                    dfs(x,y,maxr);
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) if(vis[i]) {
        ans += 1;
    }
    cout << ans << "\n";
}
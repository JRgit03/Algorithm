/*
    题意：给定n个糖果, m种类型, l[i] 表示 选择第i种糖果至少要选择l[i]个, 要么不选, 
          n行每个糖果有ai价值和属于的种类bi，求 S/C 的最大值的最简式gcd(s,c) = 1
          S = 已选糖果的 ai 之和，C = 已选糖果种类数量最多的数量 例如选了种类为1的3个，种类为2的2个则 C = 3
    思路： 贪心 + 前缀和处理
          种类相同的时候尽可能选a值大的, 同时因为第i种糖果至少要l[i]个, 将前l[i]个看出整体打包成一个，相同层之前的全选
          枚举分母, 分字为层数<=当前层数的a值前缀和， 更新答案
*/
const int N = 1e5 + 10;
int n,m;
int l[N];
vector<int> g[N];

void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        g[i].clear(); cin>>l[i];
    }
    for(int i=1;i<=n;i++){
        int a,b; cin>>a>>b;
        g[b].push_back(a);
    }
    vector<array<int,2>> all; // {{val,层数}...}
    for(int i=1;i<=m;i++){
        if(g[i].size() < l[i]) continue;
        sort(g[i].begin(), g[i].end(), greater<int>() );
        int sum = 0;
        for(int j=0;j<l[i];j++) sum += g[i][j];
        all.push_back({sum, l[i]});
        for(int j=l[i];j<g[i].size();j++) all.push_back({g[i][j], j+1});
    }
    sort(all.begin(), all.end(), [&](auto &p, auto &q){
        return p[1] < q[1];
    });
    // for(auto v : all) cout << v[0] << " " << v[1] << "\n"; cout << "\n";
    int ans1 = 0, ans2 = 1, sum = 0; // ans1 / ans2
    for(int i=0;i<all.size();i++){
        int j = i;
        while(j<all.size() && all[i][1] == all[j][1]) {
            sum += all[j][0];
            j += 1;
        }
        if(ans1 * all[i][1] <= sum * ans2) {
            ans1 = sum / __gcd(all[i][1], sum);
            ans2 = all[i][1] / __gcd(all[i][1], sum);
        }
        i = j - 1;
    }
    cout << ans1 << "/" << ans2 << "\n";
}

/*
    题意：给定一段文章空格隔开,第一个操作：将文章的单词A全部替换为单词B，第二个操作：将第x个单词替换为S
          n<=1e5, |si| <= 20, 
    思路： 维护映射 字符串 -> id集合, 第一个操作直接启发式合并, 
                                    第二个操作新增操作，但是需要额外维护字符串更新时间，时间戳大的更新为答案
*/
const int N = 1e5 + 10;
int n,m;
typedef pair<int,int> PII;
map<string, set<PII>> mp; // str -> ids = {{id, lastUp}....}
int last[N]; // last update
string ans[N];

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) last[i] = -1;
    for(int i=1;i<=n;i++) {
        string s; cin>>s;
        mp[s].insert({i,0});
    } 
    for(int i=1;i<=m;i++){
        int op; cin>>op;
        if(op == 1){ 
            string a,b; cin>>a>>b;
            if(a == b) continue;
            // merge mp[a] -> mp[b]
            if(mp[a].size() > mp[b].size()) swap(mp[a], mp[b]); 
            mp[b].insert(mp[a].begin(), mp[a].end());
            mp[a].clear();
        }else{
            int x; string s; cin>>x>>s;
            mp[s].insert({x, i});
        }
    }
    for(auto &[s, st] : mp)
        for(auto &[id, t] : st){
            if(t > last[id]){
                ans[id] = s; 
                last[id] = t;
            }
        }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}
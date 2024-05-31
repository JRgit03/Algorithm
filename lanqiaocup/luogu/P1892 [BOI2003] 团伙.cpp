// https://www.luogu.com.cn/record/160600900
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e3 + 10;
int n,m;
int p[N];

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void merge(int a,int b){
    int pa = find(a), pb = find(b);
    if(pa != pb){
        p[pa] = pb;
    }
}

vector<int> e[N];

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i] = i;
    for(int i=0;i<m;i++){
        char c; int a,b; cin>>c>>a>>b;
        if(c == 'F') merge(a, b);
        else{
            for(auto &x : e[a]) merge(b, x);
            for(auto &x : e[b]) merge(a, x);
            e[a].push_back(b);
            e[b].push_back(a);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) if(i == find(i)) {
        ans += 1;
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}

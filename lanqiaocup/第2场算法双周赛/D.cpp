#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define endl "\n"
#define dbug(x) cout << 'x = ' << x << endl
#define int long long
using namespace std;
const int N = 1e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef long long ll;
int n,sum,ans;
int s[N],k[N];
int st[N];
vector<int> g[N];

void solve(){
    memset(st,false,sizeof st);
    cin>>n>>sum;
    for(int i=1;i<=n;i++){
        int fa;cin>>fa>>s[i]>>k[i];
        if(fa) g[fa].push_back(i);
    }
    priority_queue<PII,vector<PII>,greater<PII> > heap;
    heap.push({k[1],1}); st[1] = 1;
    for(auto v : g[1]) {
        heap.push({k[v],v}); st[v] = 1;
    }
    
    while(heap.size()){
        auto [tar,ver] = heap.top(); heap.pop();
        if(sum >= tar){
            ans ++;
            sum += s[ver];
            for(auto v : g[ver]){
                // cout << ver << " " << v << "\n";
                if(!st[v]){
                    st[v] = 1;
                    heap.push({k[v],v});
                }
            }
        }else break;
    }
    cout << ans << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}

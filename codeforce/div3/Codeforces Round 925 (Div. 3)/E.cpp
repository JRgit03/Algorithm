#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define SETPRECISION cout << fixed << setprecision(10);
#define dbug(x) cout << #x << '=' << x << endl
#define debug_(x) cerr << #x << " = " << (x) << ' '
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debugsq(x) cerr << #x << ": ["; for (auto i : x) cerr << i << ' '; cerr << "]\n";
#define debugmp(x) cerr << #x << ": [ "; for (auto [i, j] : x) cerr << '[' << i << "," << j << "] "; cerr << "]\n";
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

int max(int a,int b){
    return a >= b ? a : b;
}

int f(int x,int y){
    return ((x % y) + y) % y; 
}

struct Node{
    int l,r,len,sz;

    bool operator < (const Node &o) const {
        return (sz != o.sz) ? sz < o.sz : len < o.len;
    }
};

void solve(){
    int n,m; cin>>n>>m;
    priority_queue<Node> heap;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        int l = s[0] - '0', r = s.back() - '0', len = s.length(), sz = -1;
        if(r == 0){
            sz = 0; int j = len - 1;
            while(j >= 0 && s[j] == '0'){
                j--;  
                sz++;
            }
            heap.push({l,r,len,sz});
        }else{
            heap.push({l,r,len,sz});
        }
    }
    int t = 0; while(heap.size() >= 2){
        t++;
        if(t & 1){ // Anna
            if(heap.top().sz == -1) continue;
            auto [l,r,len,sz] = heap.top(); heap.pop();
            // dbug(sz);
            heap.push({l,r,len-sz,-1});
        }else{ //Sasha 
            auto [l1,r1,len1,sz1] = heap.top(); heap.pop();
            auto [l2,r2,len2,sz2] = heap.top(); heap.pop();
            // dbug(sz1); dbug(sz2);
            heap.push({l1,r2,len1+len2,sz2});
        }
    }
    auto [l,r,len,sz] = heap.top();
    if(sz != -1) len -= sz;
    // dbug(sum); 
    cout << (len >= m + 1 ? "Sasha" : "Anna") << "\n";
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}

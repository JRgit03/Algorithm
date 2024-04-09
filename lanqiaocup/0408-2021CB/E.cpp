#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b) { return (a > b ? a : b);}
int min(int a,int b) { return (a < b ? a : b);}

const int N = 2021 + 10;
typedef pair<int,int> PII;
int n;
int st[N];
int dist[N];
vector<PII> g[N];

int gcd(int a,int b){
    return b ? gcd(b, a % b) : a;
}

void dij(int s){
    memset(dist, 0x3f, sizeof dist); 
    priority_queue<PII,vector<PII>,greater<PII> > heap;
    dist[s] = 0;
    heap.push({dist[s], s}); 
    while(heap.size()){
        int distance = heap.top().first, u = heap.top().second;
        heap.pop();
        
        if(st[u]) continue;
        st[u] = 1;
        for(auto &item : g[u]){
            int v = item.first, w = item.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                heap.push({dist[v], v});
            }
        }
    }
}

void solve(){
    for(int i=1;i<=2021;i++)
        for(int j=1;j<=2021;j++){
            if(abs(i - j) <= 21){
                int w = i * j / gcd(i, j);
                g[i].push_back({j,w});
                g[j].push_back({i,w});
            }
        }  
    dij(1);
    cout << dist[2021] << "\n"; // 10266837
}

signed main(){
    IOS; solve();
    return 0;
}


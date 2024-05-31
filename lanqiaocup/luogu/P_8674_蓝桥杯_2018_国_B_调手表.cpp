#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int n,k;
int dist[N];

void solve(){
    cin>>n>>k;
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    
    while(q.size()){
        int a = q.front(), b = -1; q.pop();

        b = (a + k) % n;
        if(dist[b] > dist[a] + 1){
            dist[b] = dist[a] + 1;
            q.push(b);
        }

        b = (a + 1) % n;
        if(dist[b] > dist[a] + 1){
            dist[b] = dist[a] + 1;
            q.push(b);
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, dist[i]);
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}

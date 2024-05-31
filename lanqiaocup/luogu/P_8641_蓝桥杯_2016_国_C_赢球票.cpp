#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e6 + 10;
int n;
int ans;
int vis[N];
int a[N];

void f(int st){
    for(int i=0;i<n;i++) vis[i] = 0;
    deque<int> q;
    int i = st; while(!vis[i]) {
        vis[i] = 1;
        q.push_back(a[i]);
        i = (i + 1) % n;
    }
    int num = 1, res = 0;; i = st; 
    while(q.size() && num <= n){
        int x = q.front(); q.pop_front();
        if(x == num) {
            num = 1;
            res += x;
        }else{
            num += 1;
            q.push_back(x);
        }
    } 
    ans = max(ans, res);
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) f(i);
    cout << ans << "\n";    
}

signed main(){
    IOS;
    solve();
    return 0;
}

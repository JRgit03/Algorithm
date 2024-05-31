/**
 *  题意：每种巧克力单价a,保质期b,数量c,要求1~x天每个吃一块巧克力,求最小代价
 *  贪心策略：优先队列维护第i天的最低价,从后往前枚举天数,保证后面的先满足
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e5 + 10;
int n,x;

struct Node{
    int a,b,c;
    // expression = true o对象排前面
    bool operator < (const Node& o) const {
        return a > o.a;  
    }
}vec[N];

void solve(){
    cin>>x>>n;
    for(int i=1;i<=n;i++){
        int a,b,c; cin>>a>>b>>c;
        vec[i] = {a,b,c};
    }     
    
    sort(vec + 1, vec + 1 + n, [&](auto &p, auto &q){
        return p.b > q.b;
    });

    priority_queue<Node> heap;
    int ans = 0, now = 1;
    for(int i=x;i>=1;i--){
        
        while(now <= n && vec[now].b >= i) {
            heap.push(vec[now]); 
            now += 1;
        }

        if(heap.size() == 0){
            cout << -1 << "\n";
            return;
        }

        auto [a,b,c] = heap.top(); heap.pop();
        //cerr << a << " " << b << " " << c << "\n";
        ans += a;
        if(c - 1 > 0) heap.push({a,b,c-1});
    }
    
    cout << ans << "\n";
    return;
}

signed main(){
    IOS;
    solve();
    return 0;
}

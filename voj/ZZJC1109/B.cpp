/**
 * difficulty: 397
 * https://atcoder.jp/contests/abc086/tasks/arc089_a
 * 
 * 题意：询问每步是否都是合法的 (a,b) -> (c,d) 能否在t秒内到达
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
int t[maxn],x[maxn],y[maxn];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>t[i]>>x[i]>>y[i];
    bool f = true;
    for(int i=1;i<=n;i++) {
        int dis = abs(x[i]-x[i-1]) + abs(y[i]-y[i-1]); // d = |xi - xj| + |yi - yj| 曼哈顿距离
        int dif = t[i] - t[i-1]; 
        if(!(dif >= dis && (dif - dis) % 2 == 0)) f = false;
    }
    cout << (f ? "Yes" : "No") << "\n";
    return 0;
}

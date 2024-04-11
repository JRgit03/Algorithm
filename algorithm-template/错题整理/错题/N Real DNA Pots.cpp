/**
 * 题意：给定n个点(xi,yi)，要求你选k个点最大化两两斜率的最小值, k<=n<=1e5, xi,yi<=1e9, 保证Xi<Xi+1
 * 思路：考虑二分答案w, 对于i<j的两点, yj-yi / xj-xi >= w => yi-w*xi<=yj-w*xj 
 *      => 将点xiyi视为 yi-w*xi => 原问题转换为LIS问题,最长递增子序列的大小>=k 
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n,m;
double x[N],y[N];

// 最大化最小值, 二分答案
int check(double w){
    vector<double> nums(n),g;
    for(int i=0;i<n;i++) nums[i] = y[i] - w * x[i];
    for(auto x : nums){
        auto it = lower_bound(g.begin(), g.end(), x);
        if(it == g.end()) g.push_back(x);
        else *it = x;
    }
    return g.size() >= m;
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    double l = -1e9, r = 1e9;
    for(int i=0;i<100;i++){
        double mid = (l + r) / 2.0;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(10) << r << "\n";
}

signed main(){
    solve();
    return 0;
}

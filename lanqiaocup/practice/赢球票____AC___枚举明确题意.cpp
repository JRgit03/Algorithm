// https://www.lanqiao.cn/problems/94/learning/?page=1&first_category_id=1&second_category_id=3&tags=%E5%9B%BD%E8%B5%9B
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e2 + 10;
int n;
int a[N];
int del[N];

// AC 100
// 双端队列模拟
void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int ans = 0;
    for(int i=0;i<n;i++){
        int res = 0, num = 1; 
        deque<int> q;
        for(int k=0;k<n;k++) q.push_back(a[(i + k) % n]);
        while(num <= n && q.size()){
            if(q.front() == num){
                num = 1;
                res += q.front(); q.pop_front();
            }else{
                num += 1;
                int x = q.front(); q.pop_front();
                q.push_back(x);
            }
        }
        ans = max(ans, res);
    }
    cout << ans << "\n";
}

// AC 100
// 从任意一张卡片开始数数 不是跳着卡片数！！
// void solve(){
//     cin>>n;
//     for(int i=0;i<n;i++) cin>>a[i];
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         int res = 0, sz = n, num = 1; 
//         for(int j=0;j<n;j++) del[j] = 0;
//         for(int j=i;num<=n;j=(j+1)%n){
//             if(sz <= 0) break;
//             if(del[j]) continue;
//             if(a[j] == num){
//                 num = 1;
//                 sz -= 1;
//                 del[j] = 1;
//                 res += a[j];
//             }else{
//                 num += 1;
//             }
//         }
//         ans = max(ans, res);
//     }
//     cout << ans << "\n";
// }

signed main(){
    IOS;
    solve();
    return 0;
}
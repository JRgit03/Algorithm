 /**
 * 模拟 map
 * https://atcoder.jp/contests/abc208/tasks/abc208_c
 * 
 * 题意：k个甜品分给n个人  k>=n 每人一个 k<n 分给id第k小的人
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n,k;
int a[N];
int id[N];
int ans[N];
signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        id[i] = i;
    }
    int c = k / n , d = k % n;
    sort(id+1,id+1+n,[&](int i,int j){
        return a[i] < a[j];
    });
    for(int i=1;i<=n;i++) ans[id[i]] = c + (i <= d ? 1 : 0);
    for(int i=1;i<=n;i++) cout << ans[i] << "\n";
    return 0;
}

// 5 12 
// c = 2 , d = 2
// k = 2
// 2 1 1~k
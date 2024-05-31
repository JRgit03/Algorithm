#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e5 + 10;
int n,g;
int a[N];
int b[N];

// 二分作法
// void solve(){
//     cin>>n>>g;
//     for(int i=1;i<=n;i++) {
//         cin>>a[i]; b[i] = (a[i] % g != 0);
//         b[i] += b[i - 1];
//     }
//     int ans = 0;
//     for(int i=1;i<=n;i++){
//         int l = i, r = n;
//         while(l < r){
//             int mid = (l + r + 1) >> 1;
//             if(b[mid] - b[i - 1] <= 1) l = mid;
//             else r = mid - 1;
//         }
//         int j = r;
//         ans += j - i;
//     }
//     cout << ans << "\n";
// }

// 双指针写法
void solve(){
    cin>>n>>g;
    for(int i=1;i<=n;i++) {
        cin>>a[i]; b[i] = (a[i] % g != 0);
    }
    int ans = 0, sum = 0;
    for(int l=1,r=1;r<=n;r++){
        sum += b[r];
        while(l <= r && sum > 1) {
            sum -= b[l];
            l += 1;
        }
        if(l <= r && sum <= 1) ans += r - l; 
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
/*
题解：
如果一个区间内都是g的倍数，那么随便改一个为g，近似GCD为g
如果有一个不为g的倍数，那么把这个数改成g，近似GCD为g
把a中不是g的倍数标记为1，否则为0，则问题转化为求区间和小于等于1的区间个数 
 */

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int x; cin>>x; 
    if(x < 0) x = -x;
    int l=0,r=1e9;
    while(l < r){
        int mid = l + r >> 1;
        if((1 + mid) * mid / 2 >= x) r = mid;
        else l = mid + 1;
    }
    if((r * (r + 1) / 2 - x) & 1) r++;
    if((r * (r + 1) / 2 - x) & 1) r++;
    cout << r << "\n";
    return 0;
}

// 二分第一个>=x的点y
// 如果 y - x 为 偶数 则 必定存在 (y - x) / 2 反方向跳 最优 
//               奇数 则 继续跳至 y - x 为偶 可以证明最多跳两次！

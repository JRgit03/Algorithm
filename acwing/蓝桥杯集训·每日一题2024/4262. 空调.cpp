#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int p[N],t[N];
int a[N],b[N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>t[i];
    int neg = 0, pos = 0;
    for(int i=1;i<=n;i++) {
        a[i] = p[i] - t[i];
        b[i] = a[i] - a[i-1];
        if(b[i] > 0) pos += b[i];
        else neg += (-b[i]);
    }
    cout << max(pos, neg) << "\n";
    return 0;
}

// 将 t数组 -> p数组
// 每一次操作: 做一段[L,R] +1 / -1 求操作数最小


// 求变化量 a = p - t
// 即 要求将 全0数组 -> a 每次可区间加一或者减一（差分思想）
// <=> 
// 求出a的差分数组b 要求每次选择L,R 加1或者减一 使得 差分数组变为全0
// 显然： 使数组全部变为0的最少操作方案就是 差分数组中负数和与正数和的绝对值的最大值
// 1. (L) +1  (R+1) -1
// 2. (L) -1  (R+1) +1
// 假设正数全部满足则负数肯定可以凑出来
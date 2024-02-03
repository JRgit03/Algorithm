// 中位数贪心
// 将所有士兵置于同一水平线且所有士兵要求相邻
// XY轴独立
// Y:最终所有yi相同 => 贪心 取中位数 货仓选址 要求取个s 使得sum|xi - s| 最小 
// X:最终所有xi相邻 
// 假设移动后第一个士兵位置为 s + 1 则 x1 = s + 1, x2 = s + 2, x3 = s + 3 ...
// 则 每个士兵要移动的距离为 |xi - i - s|   sum|xi - i - s| 最小 将每个xi-i后再排序就可以变为货仓选址
// 移动前后士兵的相对位置不变
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> x(n),y(n);
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for(int i=0;i<n;i++) x[i] -= i;
    sort(x.begin(), x.end());
    int ans = 0;
    for(int i=0;i<n;i++) ans += abs(x[i] - x[n/2]) + abs(y[i] - y[n/2]);
    cout << ans << "\n";
    return 0;
}



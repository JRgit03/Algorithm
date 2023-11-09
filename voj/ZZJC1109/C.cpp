/**
 * difficulty: 635
 * https://atcoder.jp/contests/abc098/tasks/arc098_a
 * 
 * 题意：选择一个点i(1<=i<=n) 其他点都要朝向i(不考虑点i的朝向)的最小代价 
 *                          => (1 ~ i-1 朝西的数量) + (i+1 ~ n 朝东的数量) （前后缀分解）
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int n;
string s;
int l[maxn],r[maxn]; // l[i]表示1~i-1有多少人向西W r[i]表示i+1~n有多少人向东E 预处理

// int main(){ // E 东 W 西
//     cin>>n>>s; s = "?" + s + "?";
//     for(int i=1;i<=n;i++) l[i] += l[i-1] + (s[i-1] == 'W');
//     for(int i=n;i>=1;i--) r[i] += r[i+1] + (s[i+1] == 'E');
//     int ans = n;
//     for(int i=1;i<=n;i++) ans = min(ans,l[i]+r[i]);
//     cout << ans << "\n";
//     return 0;
// }

int main(){ // E 东 W 西
    cin>>n>>s; s = "?" + s + "?";
    int pre = 0, suf = 0;
    for(int i=2;i<=n;i++) suf += (s[i] == 'E');
    int ans = n;
    for(int i=1;i<=n;i++) {
        ans = min(ans, pre + suf);
        pre += (s[i] == 'W');
        suf -= (s[i+1] == 'E');
    }
    cout << ans << "\n";
    return 0;
}

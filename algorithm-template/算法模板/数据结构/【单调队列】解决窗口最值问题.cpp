/**
 * https://www.luogu.com.cn/problem/P1886 
 */
// 单调队列常见模型: 找出滑动窗口中的最值
// int hh = 0 , tt = -1;
// for(int i=0;i<n;i++){
//     while(hh<=tt && check(q[hh])) hh++;
//     while(hh<=tt && check(q[tt])) tt--;
//     q[++tt] = i;
// }

#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e6 + 10;
int n,k;
int a[N],q[N];

int main(){
    IOS; cin>>n>>k;
    int hh = 0 , tt = -1;
    for(int i=1;i<=n;i++) cin>>a[i];
    // 最小值 单调增 
    for(int i=1;i<=n;i++){
        while(hh<=tt && i - q[hh] + 1 > k) hh++;
        while(hh<=tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;
        if(i>=k) cout << a[q[hh]] << " \n"[i==n];
    }    
    // 最大值 单调减 
    hh = 0 , tt = -1;
    for(int i=1;i<=n;i++){
        while(hh<=tt && i - q[hh] + 1 > k) hh++;
        while(hh<=tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;
        if(i>=k) cout << a[q[hh]] << " \n"[i==n];
    }    
    return 0;
}

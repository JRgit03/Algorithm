 /**
 * 模拟 前缀和
 * https://atcoder.jp/contests/abc223/tasks/abc223_c
 * 
 * 题意：求左右两团火相遇时 左边的火离左端点的距离
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N],b[N];
double c[N];

int main(){
    int n; cin>>n;
    double s = 0, t = 0, pre = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        c[i] = a[i] * 1.0 / b[i];
        s += c[i];
    }
    s /= 2.0; // s 相遇时间 t 前i-1 时间前缀和 pre 距离前缀和
    for(int i=1;i<=n;i++){
        if(t + c[i] >= s){ // 在第i段相遇
           printf("%.10lf\n",pre + (s - t) * b[i]);
           return 0; 
        }
        t += c[i];
        pre += a[i];
    }
    return 0;
}

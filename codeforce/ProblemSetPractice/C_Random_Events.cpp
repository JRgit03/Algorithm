#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n,m;
int a[maxn];
int r[maxn];
double p[maxn];

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>r[i]>>p[i];
    int k = -1;
    for(int i=n;i>=1;i--)
        if(a[i] != i){
            k = i;
            break;
        }
    double ans = 1.0, mul = 1.0;
    if(k == -1) {
        printf("%.10lf\n",ans);
        return;
    }
    for(int i=1;i<=m;i++){
        if(r[i] >= k){
            mul *= (1 - p[i]);
        }
    }
    printf("%.10lf\n",ans - mul);
}

int main(){
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}

// 只关心从后往前第一个a[i]不等于i的下标k 即前k个元素需要排序
// 对于r[i]>=k的操作对答案有贡献
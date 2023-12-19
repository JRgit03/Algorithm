// 二分答案 二分平均值
// 是否存在一个长度不小于k的子段 字段和非负 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const double eps = 1e-6;
int n,k;
double a[N],b[N];

bool check(double base){
    for(int i=1;i<=n;i++) b[i] = b[i-1] + a[i] - base; 
    double ans = -2e9, minn = 2e9;
    for(int i=k,j=0;i<=n;i++,j++){
        minn = min(minn, b[j]);
        ans = max(ans, b[i] - minn);
    }
    return ans >= 0;
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    double l = 0, r = 2000;
    while(r - l > eps){
        double mid = (l + r) / 2; 
        if(check(mid)) l = mid;
        else r = mid;
    } 
    // printf("%d\n",int(r*1000)); // ! r的类型为double需要强转才可以正常输出 
    cout << (int)(r*1000) << "\n"; // 或者采用 cout << (int)(r*1000) << "\n";
    return 0;
}

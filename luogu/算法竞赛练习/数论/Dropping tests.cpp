/**
 * 01分数规划入门
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;;
const double eps = 1e-6;
int n,k;
double a[N],b[N],c[N];

bool cmp(double p,double q){
    return p > q;
}

int check(double x){
    double s = 0;
    for(int i=1;i<=n;i++) c[i] = a[i] - x * b[i];
    sort(c+1,c+1+n,cmp);
    for(int i=1;i<=k;i++) s += c[i];
    return s >= 0;
}

void solve(){
    k = n - k; // 选k个
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    double l = 0 , r = 1; // a[i] <= b[i] 
    while(r - l >= eps){
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    } 
    printf("%.0lf\n",100*r);
}
int main(){
    while(cin>>n>>k){
        if(!n && !k) break;
        solve();
    }
    return 0;
}

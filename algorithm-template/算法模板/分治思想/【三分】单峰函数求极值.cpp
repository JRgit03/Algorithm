/**
 * 三分求极大值
 * https://www.luogu.com.cn/problem/P3382
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 20;
const double eps = 1e-7;
int n; double l,r;
double fact[20];

double f(double x){
    double res = 0.0;
    for(int i=n;i>=0;i--) res = res * x + fact[i];
    return res;
}

int main(){
    cin>>n>>l>>r;
    for(int i=n;i>=0;i--) cin>>fact[i];
    while(r-l>=eps){
        double k = (r-l) / 3.0;
        double lmid = l + k , rmid = r - k;
        if(f(lmid) <= f(rmid)) l = lmid;
        else r = rmid;
    }
    printf("%.10lf\n",r);
    return 0;
}

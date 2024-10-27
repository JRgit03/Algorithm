#include <bits/stdc++.h>
using namespace std;
// 0.0001
const double eps = 1e-6;

void solve(){
    double l = 2, r = 3;
    for(int i=0;i<100;i++){
        double mid = (l + r) / 2.0;
        if(mid * mid - 7 >= 0) r = mid;
        else l = mid;
    }
    printf("%.10lf\n", r);
}

int main(){
    solve();
    return 0;
}

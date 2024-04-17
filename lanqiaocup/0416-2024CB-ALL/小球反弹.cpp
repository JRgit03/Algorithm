#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

int gcd(int a,int b){
    return b ? gcd(b, a % b) : a;
}

void solve(){
    int x = 343720, y = 233333;
    int d = gcd(15 * y, 17 * x);
    int k1 = 15 * y / d, k2 = 17 * x / d;
    cout << k1 << " " << k2 << "\n"; // 1059 1768
    double t = 2.0 * x * k1 / 15, t2 = 2.0 * y * k2 / 17;
    cout << t << " " << t2 << "\n";
    double dx = t * 15, dy = t2 * 17;
    double ans = sqrt(dx*dx+dy*dy);
    printf("%.10lf\n", ans); // 1100325199.7703950405
}

signed main(){
    solve();
    return 0;
} 

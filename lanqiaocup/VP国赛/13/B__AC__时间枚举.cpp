#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e6 + 10;

void solve(){
    for(int s=0;s<=6;s++){
        for(int f=0;f<60;f++){
            for(int m=0;m<60;m++){
                if(!s && !f && !m) continue;
                double a = s / 12.0 * 360.0 + f / 60.0 / 12.0 * 360.0 + m / 60.0 / 60.0 / 12.0 * 360.0;
                double b = f / 60.0 * 360.0 + m / 60.0 / 60.0 * 360.0;
                double c = m / 60.0 * 360;
                // AB角度是0~180!
                double A = min(fabs(a - b), 360 - fabs(a - b));
                double B = min(fabs(b - c), 360 - fabs(b - c));
                if(fabs(A - 2 * B) <= 1e-8) {
                    cout << s << " " << f << " " << m << "\n";
                }
            }
        }
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}

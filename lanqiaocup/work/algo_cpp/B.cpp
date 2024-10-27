#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
int x[110];

void solve(){
    int n = 51;
    double ans = 0, p = 1.0 / (51.0 * 50.0 / 2.0);
    for(int a=1;a<=n;a++){
        for(int b=a+1;b<=n;b++){
            for(int c=1;c<=n;c++){
                for(int d=c+1;d<=n;d++){
                    
                    for(int i=1;i<=n;i++) x[i] = i;
                    swap(x[a], x[b]); swap(x[c], x[d]);
                    
                    int cnt = 0;
                    for(int i=1;i<=n;i++){
                        for(int j=i+1;j<=n;j++){
                            cnt += (x[i] > x[j]);
                        }
                    }
                       
                    ans += cnt * p * p;                  
                    for(int i=1;i<=n;i++) x[i] = i;
                    swap(x[c], x[d]); swap(x[a], x[b]);
                    
                    cnt = 0;
                    for(int i=1;i<=n;i++){
                        for(int j=i+1;j<=n;j++){
                            cnt += (x[i] > x[j]);
                        }
                    }
                       
                    ans += cnt * p * p;
                    
                }
            }
        }
    }
    cout << ans << "\n";
    printf("%.2lf\n", ans); 
    // 65.33
    // 65.3333
    
    // 130.67
    // 130.667
}

signed main(){
    IOS;
    solve();
    return 0;
} 

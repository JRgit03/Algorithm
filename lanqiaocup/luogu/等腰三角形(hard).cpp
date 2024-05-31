#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 3e3 + 10;
int n;
int x[N],y[N];

double getD(int i,int j){
    double dx = x[i] - x[j], dy = y[i] - y[j];
    return sqrt(dx * dx + dy * dy);
}

int get(int i,int j){
    int dx = x[i] - x[j], dy = y[i] - y[j];
    return dx * dx + dy * dy;
}

// O(n^3)
void solve1(){
    int ans = 0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++){
                double lena = getD(i, j), lenb = getD(i, k), lenc = getD(j, k);
                vector<double> len = {lena, lenb, lenc};
                sort(len.begin(), len.end()); debug(len);
                if(len[0] + len[1] > len[2]){
                    if(len[0] == len[1] || len[0] == len[2] || len[1] == len[2]) ans += 1;
                }
            }
    cout << ans << "\n";
}


int mp[4000000 + 10];
int st[3010][3010];
// O(n^2)
void solve2(){
    int ans = 0;
    for(int i=1;i<=n;i++) st[x[i] + 1500][y[i] + 1500] = 1;
    for(int i=1;i<=n;i++){ // 枚举圆心点
        int cnt = 0;
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            ans += mp[get(i, j)];
            mp[get(i, j)] += 1;

            int u = 2 * x[i] - x[j], v = 2 * y[i] - y[j];
            if(st[u + 1500][v + 1500]) cnt += 1;
        }
        ans -= cnt / 2;
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            mp[get(i, j)] -= 1;
        }
    }
    cout << ans << "\n";
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    if(n <= 500) solve1();
    else solve2();
}

signed main(){
    IOS;
    solve();
    return 0;
}

#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e3 + 10;
int n;
char d[N];
int x[N],y[N],v[N],vx[N],vy[N];

int ans;
void calc(int x[], int vx[]){
    for(int i=1;i<=n;i++){
        map<int,int> mp; int res = 1;
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            if(vx[i] == vx[j]){
                if(x[i] == x[j]) res += 1;
                continue;
            }
            int dx = x[j] - x[i], dv = vx[i] - vx[j];
            int t = dx / dv;
            if(t < 0 || dx % dv != 0) continue; // 反向 or 要求非负整数时刻释放轨道炮
            mp[t] += 1;
        }
        ans = max(ans, res);
        for(auto &[v, sz] : mp) ans = max(ans, sz + res);   
    }
}

// 横向射与纵向射问题互相独立
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>v[i]>>d[i];
        if(d[i] == 'L') vx[i] = -v[i];
        else if(d[i] == 'R') vx[i] = v[i];
        else if(d[i] == 'U') vy[i] = v[i];
        else if(d[i] == 'D') vy[i] = -v[i];
    }
    calc(x, vx);
    calc(y, vy);
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
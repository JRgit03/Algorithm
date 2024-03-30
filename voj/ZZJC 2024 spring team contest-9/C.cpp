#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 10;
int n;
int h,w;

double x[N],y[N];
double getdist(int i,int j){
    double dx = x[j] - x[i], dy = y[j] - y[i];
    return sqrt(dx * dx + dy * dy);    
}

int p[N];
int sum[N];
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void merge(int a,int b){
    int pa = find(a), pb = find(b);
    if(pa != pb){
        p[pa] = pb;
        sum[pb] |= sum[pa];
    }
}

int check(double r){
    int suc = 1;
    // up & left
    for(int i=1;i<=n;i++){
        p[i] = i;
        if(h - y[i] <= r) sum[i] = 1;
        else if(x[i] <= r) sum[i] = 2;
        else sum[i] = 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(getdist(i, j) <= 2.0 * r) 
                merge(i, j);
    for(int i=1;i<=n;i++)
        if(y[i] <= r || w - x[i] <= r)
            if(sum[find(i)] >= 1)
                suc = 0;
    // (0,0) & (w,h)
    for(int i=1;i<=n;i++)   
        if(getdist(i, 0) <= r || getdist(i, n+1) <= r)
            suc = 0;
    return suc;
}

void solve(){
    cin>>w>>h;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    x[0] = 0, y[0] = 0;
    x[n+1] = w, y[n+1] = h; 
    
    double l = 0, r = getdist(0, n+1);
    for(int i=0;i<100;i++){
        double mid = (l + r) / 2.0;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(10) << r << "\n";
}

signed main(){
    solve();
    return 0;
}

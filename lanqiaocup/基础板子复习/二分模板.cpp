/*

最大值模板：
int mid = (l + r + 1) >> 1;
if(check()) l = mid
else r = mid - 1

最小值模板：
int mid = (l + r) >> 1;
if(check()) r = mid
else l = mid + 1

*/

#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e4 + 10, up = 1e9;
int n;
int a[N];
int b[N];
int ans1,ans2;

int check1(int v){
    for(int i=1;i<=n;i++)
        if(!(a[i] / v <= b[i])) return 0;
    return 1;
}

int check2(int v){
    for(int i=1;i<=n;i++)
        if(!(a[i] / v >= b[i])) return 0;
    return 1;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    int l = 1, r = up;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check1(mid)) r = mid;
        else l = mid + 1; 
    }
    ans1 = r;
    l = 1, r = up;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(check2(mid)) l = mid;
        else r = mid - 1;
    }
    ans2 = r;
    cout << ans1 << " " << ans2 << "\n"; 
}

signed main(){
    IOS;
    solve();
    return 0;
}

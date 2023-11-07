#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 10;
int n,m;
int a[maxn],b[maxn];

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    auto check = [&](int x){
        int l,r;
        int cnt1 = 0,cnt2 = 0;
        l = 1, r = n;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(a[mid] <= x) l = mid;
            else r = mid - 1;
        }
        if(a[r] <= x) cnt1 = r;
        l = 1, r = m;
        while(l < r){
            int mid = l + r >> 1;
            if(b[mid] >= x) r = mid;
            else l = mid + 1;
        }
        if(b[r] >= x) cnt2 = m - r + 1;
        return cnt1 >= cnt2;
    };
    int l = 0, r = 2e9;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }    
    cout << r << "\n";
    return 0;
}

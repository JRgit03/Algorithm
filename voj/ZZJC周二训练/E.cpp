#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n,D,P;
int a[N];

signed main(){
    cin>>n>>D>>P;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    int sz = n / D + (n % D != 0);
    vector<int> vec;
    for(int i=1;i<=sz;i++){
        int l = (i - 1) * D + 1, r = min(n,i*D);
        int s = 0;
        while(l <= r) s += a[l++];
        vec.push_back(s);
    }
    int ans = 0;
    for(int i=0;i<sz;i++) ans += min(vec[i],P);
    cout << ans << "\n";
    return 0;
}

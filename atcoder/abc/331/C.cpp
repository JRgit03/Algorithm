#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn],b[maxn],c[maxn];
signed main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        a[i] = b[i] = c[i] = x;
    }
    sort(b+1,b+1+n); //for(int i=1;i<=n;i++) cout << b[i] << " "; cout << "\n";
    sort(c+1,c+1+n); for(int i=1;i<=n;i++) c[i] += c[i-1];
    for(int i=1;i<=n;i++){
        int l = 1, r = n;
        while(l < r){
            int mid = l + r >> 1;
            if(b[mid] >= a[i] + 1) r = mid;
            else l = mid + 1;
        }
        // cout << r << "\n";
        if(b[r] < a[i] + 1) cout << 0 << " ";
        else cout << c[n] - c[r-1] << " "; 
    }
    return 0;
}

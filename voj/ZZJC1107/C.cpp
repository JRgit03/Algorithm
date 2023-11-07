#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 10;
int n;
int a[maxn],b[maxn];
signed main(){
    cin>>n;
    int sum = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i]; sum += a[i];
    } 
    int tar = sum / n , k = sum % n, ans = 0;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) b[i] = tar + (n-i+1 <= k);
    for(int i=1;i<=n;i++) ans += abs(a[i] - b[i]);
    cout << (ans/2) << "\n";
    return 0;
}
 
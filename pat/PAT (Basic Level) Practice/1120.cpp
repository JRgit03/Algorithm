#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int n,m,ans;
int s[maxn];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        s[i] += s[i-1];
    }
    for(int i=1;i<=n;i++){
        int l = i, r = n;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(s[mid] - s[i-1] <= m) l = mid;
            else r = mid - 1;
        }
        if(s[r] - s[i-1] <= m) ans += r - i + 1;
    }
    cout << ans << "\n";
    return 0;
}

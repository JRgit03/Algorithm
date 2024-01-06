#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int l = 1, r = 1e9;
    int ans = 0;
    while(l < r){
        int mid = l + r >> 1;
        if(mid < n) ans += 1, l = mid + 1;
        else r = mid;
    }
    cout << ans << "\n";
    return 0;
}

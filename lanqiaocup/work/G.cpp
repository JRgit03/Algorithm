#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int max(int a,int b){ return a > b ? a : b;}
int min(int a,int b){ return a < b ? a : b;}

const int N = 1e5 + 10;
int n;
int a[N]; 

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n == 1){
        cout << 1 << "\n";
        return;
    }
    int ans = 2;
    if(n <= 1000){
        for(int i=1;i<=n;i++){
            for(int j=i+2;j<=n;j++){
                int sz = 0;
                for(int k=i+1;k<=j-1;k++){
                    if(a[i] > a[k] && a[j] > a[k]){
                        sz += 1;
                    }
                }
                ans = max(ans, sz + 2);
            }
        }
    }   
    for(int l=1;l<=min(1000, n) && l <= n / 2;l++) {
        int r = n - l + 1;
        int sz = 0;
        for(int k=l+1;k<=r-1;k++){
            if(a[l] > a[k] && a[r] < a[k]){
                sz += 1;
            }
        }
        ans = max(ans, sz);
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
} 

/*
3
3 1 2

3
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,x; cin>>n>>m>>x;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i]; sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<m;i++) cin>>b[i]; sort(b.begin(),b.end(),greater<int>());
    int ans = 0, i = 0, j = 0;
    while(i < n && j < m){
        if(x <= 0){
            cout << ans << "\n";
            return 0;
        }
        if(x - b[j] <= 0){
            ans += 1;
            cout << ans << "\n";
            return 0;
        }else{
            ans += 2;
            x -= b[j] * a[i];
            i += 1; j += 1;
        }
    }
    while(j < m){
        if(x <= 0){
            cout << ans << "\n";
            return 0;
        }
        x -= b[j];
    }
    if(x > 0) ans = -1;
    cout << ans << "\n";
    return 0;
}

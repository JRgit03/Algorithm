#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> w(n),x(n);
    for(int i=0;i<n;i++) cin>>w[i]>>x[i];
    int ans = 0;
    for(int i=0;i<=23;i++){
        int res = 0;
        for(int j=0;j<n;j++){
            int k = (i + x[j]) % 24;
            if(k >= 9 && k <= 17) res += w[j];
        }
        ans = max(ans,res);
    }
    cout << ans << "\n";
    return 0;
}

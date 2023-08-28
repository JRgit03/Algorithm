#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a[i] = b[i] = x;
    }
    sort(b.begin()+1,b.end());
    
    if(n&1){
        int k = b[(n+1)/2] , cur = 0;
        for(int i=1;i<=n;i++){
            if(a[i] < k) cur++;
            if(a[i] > k) cur--;
            if(cur < 0){
                cout << 0 << "\n";
                return 0;
            }
        }
        if(cur==0) cout << 1 << "\n";
        else cout << 0 << "\n";
    }else{
        int kl = b[(n+1)/2] , kr = b[(n+2)/2];
        if(kl==kr){
            int cur = 0;
            for(int i=1;i<=n;i++){   
                if(a[i] < kl) cur++;
                if(a[i] > kl) cur--;
                if(cur < 0){
                    cout << 0 << "\n";
                    return 0;
                }
            }   
            if(cur==0) cout << 1 << "\n";
            else cout << 0 << "\n";
        }else{
            int res = kr - kl - 1 , add = 0;
            int cur = 0;
            for(int i=1;i<=n;i++){
                if(a[i] < kl) cur++;
                if(a[i] > kl) cur--;
                if(cur < 0) break;
            }   
            if(cur==0) add++;
            cur = 0;
            for(int i=1;i<=n;i++){
                if(a[i] < kr) cur++;
                if(a[i] > kr) cur--;
                if(cur < 0) break;
            }   
            if(cur==0) add++;
            if(add == 2) cout << res + add << "\n";
            else cout << add << "\n";
        }
    }

    return 0;
}

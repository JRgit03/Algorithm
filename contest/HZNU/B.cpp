#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;cin>>n;

    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    
    sort(b.begin()+1,b.end());
    
    if(n==1){
        cout << min(abs(a[1]-b[1]),abs(-a[1]-b[1])+1) << "\n";
        return 0;
    }

    int res = 0x3f3f3f3f;

    //不翻转a
    int dif;
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;i++){
        if(i==1) dif = a[i] - b[i];
        else if(dif != a[i] - b[i])break;
    
        if(i==n) res = abs(dif);
    }

    //翻转a
    for(int i=1;i<=n;i++) a[i] = -a[i];
    sort(a.begin()+1,a.end());

    for(int i=1;i<=n;i++){
        if(i==1) dif = a[i] - b[i];
        else if(dif != a[i] - b[i])break;
    
        if(i==n) res = min(abs(dif) + 1 , res);
    }

    if(res == 0x3f3f3f3f) res = -1;
    cout << res << "\n";
    return 0;
}

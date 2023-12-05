#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,a,b,c; cin>>n>>a>>b>>c;
    int ans = LONG_LONG_MAX;
    for(int i=0;i<=100;i++)
        for(int j=0;j<=100;j++)
            for(int k=0;k<=100;k++)
                if(6*i+8*j+12*k>=n)
                    ans = min(ans,i*a+j*b+k*c);
    cout << ans << "\n";
    return 0;
}

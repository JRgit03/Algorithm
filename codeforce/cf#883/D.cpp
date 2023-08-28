#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
	int n,d,h;cin>>n>>d>>h;
    int pre;double ans = 0.0;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    reverse(v.begin(),v.end());
    for(int i=0;i<n;i++){
        double b = v[i];
        if(!i) ans += d * h * 1.0 / 2.0 , pre = b;
        else{
            if(b+h<=pre) ans += d * h * 1.0 / 2 , pre = b;
            else{
                int h2 = pre - b , h1 = h - h2;
                double sd = d * h1 * 1.0 / h ;
                ans += (sd + d) * h2 * 1.0 / 2.0 , pre = b;
            }
        }
    }
    printf("%.10lf\n",ans);
}

signed main(){
	int t;cin>>t;
    while(t--)solve();
	return 0;
}
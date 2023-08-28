#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const double eps = 1e-6;

void solve(){
    int n,m;cin>>n>>m;//n 直线  m 抛物线
    vector<int> slope(n);
    for(int i=0;i<n;i++) cin>>slope[i];
    sort(slope.begin(),slope.end());

    for(int i=0;i<m;i++){
        double a,b,c;cin>>a>>b>>c;
        double k1 = b + sqrt(4*a*c) , k2 = b - sqrt(4*a*c);
        int l = 0 , r = n-1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if(slope[mid] < k1) l = mid;
            else r = mid - 1;
        }
        int ll = 0 , rr = n-1;
        while (ll < rr)
        {
            int mid = ll + rr >> 1;
            if(slope[mid] > k2) rr = mid;
            else ll = mid + 1;
        }
		
		//cout << r << " " << rr << "\n";
		//cout << k1 << " " << k2 << "\n";
		//cout << slope[r] - k1 << " " << slope[rr] - k2 << "\n";
        if(r >= rr && slope[r] < k1 && slope[rr] > k2){
            cout << "YES" << "\n";
            cout << slope[rr] << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
    cout << "\n"; return ;
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}

#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
    int n,c,d;cin>>n>>c>>d; // c - remove  d - del

    int del = 0;
    map<int,bool> mp;
    vector<int> vec;

    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(mp[x]) del++;
        else {
            vec.push_back(x);
            mp[x] = true;
        }
    }

    sort(vec.begin(),vec.end());
    int res = n * c + d, cur=del*c; // cur 维护前面的cost
    int ed = 1;
    if(vec[0]!=ed) cur += (vec[0] - 1) * d , ed = vec[0];
    
    //cout << "init= " << res << " " << cur << "\n";

    //for(auto x : vec) cout << x << " " ; cout << "\n";
    
    n = vec.size();

    for(int i=0;i<vec.size();i++){
        int x = vec[i];
        if(x==ed) {
            int dels = (n-i-1)*c;
            //cout << (n-i-1) << " " << dels << "\n";
            res = min(res , cur+dels);
            ed++;
        }else{
            int ins = (x-(ed-1)-1) * d;
            int dels = (n-i-1)*c;  
            // cout << (x-(ed-1)-1) <<" " << n-i-1 <<  "   ";
            // cout << ins << " " << dels << "\n";
            // cout << cur+dels << "\n";
            res = min(res , cur+dels+c);
            ed = x+1;
            cur += ins;
        }    
        //cout << i << " res= " << res << "\n";
    }

    res = min(res,cur);

    cout << res << "\n";
}

signed main(){
	IOS;
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
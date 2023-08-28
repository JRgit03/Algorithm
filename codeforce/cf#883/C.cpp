#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
	int n,m,h;cin>>n>>m>>h;
    vector<pair<int,int>> fs; pair<int,int> tar;
    for(int i=1;i<=n;i++){
        vector<int> t(m+1);
        for(int j=1;j<=m;j++) cin>>t[j];
        sort(t.begin()+1,t.end());
        int sum = 0 , point = 0 , js = 0;
        for(int j=1;j<=m;j++){
            sum += t[j];if(sum > h)break;
            point += sum; js++;
        }
        if(i==1) tar = {js,point};
        fs.push_back({js,point});
    }
    sort(fs.begin(),fs.end(),[&](const auto &a , const auto &b){
        if(a.first!=b.first) return a.first > b.first;
        return a.second < b.second;
    });
    
    for(int i=0;i<n;i++){
        if(fs[i] == tar){
            cout << i+1 << "\n";
            return;
        }
    }
    
}

signed main(){
	IOS;
	int t;cin>>t;
    while(t--)solve();
	return 0;
}
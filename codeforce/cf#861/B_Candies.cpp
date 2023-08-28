#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
    int n;cin>>n;
    if(n%2==0){
        cout << -1 << "\n";
        return;
    }

    vector<int> path;
    
    while(n!=1){
        if(((n+1)/2)%2==1){
            path.push_back(1);
            n = (n+1)/2;
        }else{
            path.push_back(2);
            n = (n-1)/2;
        }
    }
    reverse(path.begin(),path.end());
    cout << (int)path.size() << "\n";
    for(auto x : path) cout << x << " "; cout<<"\n";
}

int main(){
	IOS;
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
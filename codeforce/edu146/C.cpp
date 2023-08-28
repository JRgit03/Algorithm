#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int,int> PII;

void solve(){
	int n,s1,s2;cin>>n>>s1>>s2;
    vector<PII> vec(n);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        vec[i] = {i+1,x};
    }  
    sort(vec.begin(),vec.end(),[](const PII &a , const PII &b){
        return a.second > b.second;
    });
    vector<int> va,vb;
    for(int i=0;i<n;i++){
        auto [a,b] = vec[i];//cout<<a<<" "<<b<<"\n";
        if((va.size()+1)*s1 <= (vb.size()+1)*s2) va.push_back(a);
        else vb.push_back(a);
    }
    cout << va.size() << " ";
    for(auto x : va) cout << x << " "; cout << "\n";
    cout << vb.size() << " ";
    for(auto x : vb) cout << x << " "; cout << "\n";
}

int main(){
	IOS;
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;cin>>n;
    vector<int> vec; //九进制 0~3 5~9
    while(n)vec.push_back(n%9),n/=9;
    reverse(vec.begin(),vec.end());
    for(auto &x : vec) if(x>=4) x++;
    for(int i=0;i<(int)vec.size();i++) cout<<vec[i]; cout<<"\n";
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}

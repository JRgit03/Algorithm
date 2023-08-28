#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

int main(){
    IOS;
    int a,b,n;cin>>a>>b>>n;
    vector<int> vec(3);
    vec[1] = a , vec[2] = b;
    for(int i=3;i<=n;i++){
        int val = vec[i-2] * vec[i-1];
        vector<int> v;
        while(val){v.push_back(val%10),val/=10;}
        if(!v.size())v.push_back(0);
        reverse(v.begin(),v.end());
        for(auto x : v) vec.push_back(x);
        if(vec.size() >= n+1) break;
    }
    cout << vec[1];
    for(int i=2;i<=n;i++) cout << " " << vec[i];
    return 0;
}

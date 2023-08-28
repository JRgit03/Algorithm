#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

int main(){
    IOS;
    int n;cin>>n;
    map<int,int> cnt;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        cnt[x]++;
    }
    auto [a,b] = *cnt.begin();cout<<a<<" "<<b<<"\n";
    auto [c,d] = *(--cnt.end());cout<<c<<" "<<d<<"\n";
    // for(auto [a,b] : cnt)
    //     cout << a << " " << b << "\n";
    return 0;
}

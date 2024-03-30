#include <bits/stdc++.h>
#define int long long
using namespace std;

map<int,int> get(int a,int b,int c,int d){
    map<int,int> mp;
    for(int i=a;i<=b;i++)
        for(int j=c;j<=d;j++)
            mp[i+j] += 1;
    return mp;
}

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    auto m1 = get(a,b,c,d);
    cin>>a>>b>>c>>d;
    auto m2 = get(a,b,c,d);
    int res1 = 0, res2 = 0;
    for(auto [x,y] : m1){
        for(auto [a,b] : m2){
            if(x > a) res1 += y * b;
            else if(x < a)res2 += y * b;
        }
    }
    cout << (res1 == res2 ? "Tie" : (res1 > res2 ? "Gunnar" : "Emma")) << "\n";
}

signed main(){
    solve();
    return 0;
}

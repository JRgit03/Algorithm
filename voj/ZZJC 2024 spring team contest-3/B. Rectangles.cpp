#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define int long long
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> fact1, fact2;
    auto getFact = [&](int x, vector<int> &fact){
        for(int i=1;i<=x/i;i++) 
            if(x % i == 0){
                fact.push_back(i); 
                fact.push_back(x/i);
            }
    }; 
    getFact(n, fact1); // debug(fact1.size()); 
    getFact(n + 1, fact2); // debug(fact2.size()); 
    int s = 4 * n * (n + 1);
    set<pair<int,int>> st;
    for(auto &d1 : fact1){
        for(auto &d2 : fact2){
           int d = d1 * d2;
           int y = d + 2 + 2 * n;
           int x = s / d + 2 + 2 * n;
           if(x > y) swap(x , y);
           st.insert({x,y}); 
        }
    }
    cout << st.size() << "\n";
    for(auto &[a,b] : st) cout << a << " " << b << "\n";
}

signed main(){
    solve();
    return 0;
}

// 枚举 n和n+1的所有因子 
// x = 2 + 2 * n + 4 * n * (n + 1) / (y - (2 + 2 * n))

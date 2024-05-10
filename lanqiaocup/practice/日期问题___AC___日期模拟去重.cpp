#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e6 + 10;

int f(int x){
    return (x % 400 == 0) || (x % 4 == 0 && x % 100 != 0);
}

set<int> st = {1,3,5,7,8,10,12};

void solve(){
    string a,b,c,s; cin>>s;
    a = s.substr(0,2), b = s.substr(3,2), c = s.substr(6,2);
    vector<string> ans;
    for(int y=1960;y<=2059;y++){ // 100 * 12 * 30 
        for(int m=1;m<=12;m++){
            for(int d=1;d<=(m == 2 ? (f(y) ? 29 : 28) : (st.count(m) ? 31 : 30));d++){
                string cur = "";
                cur += to_string(y);//2002-03-04
                cur += "-";
                if(m >= 1 && m <= 9) cur += "0";
                cur += to_string(m);
                cur += "-";
                if(d >= 1 && d <= 9) cur += "0";
                cur += to_string(d);
                string yy,mm,dd;
                yy = cur.substr(2,2);
                mm = cur.substr(5,2);
                dd = cur.substr(8,2);
                if(a == yy && b == mm && c == dd) ans.push_back(cur);
                else if(a == mm && b == dd && c == yy) ans.push_back(cur);
                else if(a == dd && b == mm && c == yy) ans.push_back(cur);   
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(auto &x : ans) cout << x << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}

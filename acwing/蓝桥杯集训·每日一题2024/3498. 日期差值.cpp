#include <bits/stdc++.h>
#define int long long
using namespace std;

string s1,s2;

int check(int y){
    if(y % 4 == 0 && y % 100 != 0) return 1;
    if(y % 400 == 0) return 1;
    return 0;
}

set<int> st = {1,3,5,7,8,10,12};

int calc(string s){
    int y = stoi(s.substr(0, 4));
    int m = stoi(s.substr(4, 2));
    int d = stoi(s.substr(6, 2));
    int sum = d;
    for(int i=1;i<m;i++){
        if(i == 2) sum += 28 + check(y); 
        else sum += 30 + st.count(i);
    }
    for(int i=1;i<y;i++) sum += 365 + check(i);
    return sum;
}

void solve(){
    if(s1 > s2) swap(s1, s2);
    cout << calc(s2) - calc(s1) + 1 << "\n";
}

signed main(){
    while(cin>>s1>>s2) solve();
    return 0;
}

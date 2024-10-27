#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int cnt = 0;
int ansid = -1;
vector<int> ans;

void f(int d){
    vector<int> res;
    int x = 8100178706957568;
    while(x){
        res.push_back(x % d);
        x /= d; 
    }
    int suc = 1;
    cerr << "当前进制：" << d << "  ->>>>>>>"; 
    for(auto &x : res) {
        cerr << x << " "; 
        suc &= (x <= 9);
    }
    cout << "\n";
    if(suc){
        cnt += 1;
        ansid = d;
        ans = res; 
    }   
}


void solve(){
    for(int i=11;i<=36;i++) f(i);
    cerr << "===" << "\n";
    cerr << cnt << "\n";
    cerr << "ansD: " << ansid << "\n";
    for(auto &x : ans) cerr << x << " "; cerr << "\n";
}


// D = 32 
signed main(){
    IOS;
    solve();
    return 0;
} 

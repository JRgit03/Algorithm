#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e6 + 10;
int n,a,b;
string s;
int ans;
vector<int> num;

void solve(){
    cin>>s>>a>>b;
    n = s.length();
    for(auto &c : s) num.push_back(c - '0');

    for(int i=0;i<(1<<n);i++){
        vector<int> t = num; int A = a, B = b;
        for(int j=0;j<n;j++){
            if((i >> j) & 1){
                while(t[j] < 9 && A > 0){
                    t[j] += 1; A -= 1;
                }
            }else{
                if(t[j] + 1 <= B){
                    B -= (t[j] + 1);
                    t[j] = 9;
                }
            }
        }
        int res = 0;
        for(auto &x : t) res = res * 10 + x;
        ans = max(ans, res);
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}

#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e5 + 10;
int n;
map<char,int> cnt;
string s;
int ans = 1e9;

void solve(){
    cin>>s;
    n = s.length(); s = "?" + s;
    for(int i=1;i<=n;i++) cnt[s[i]] += 1;
    vector<char> vec = {'T', 'A', 'B'};
    sort(vec.begin(), vec.end());
    do{
        int res = 0;
        map<pair<char,char>, int> mp;
        for(int i=1;i<=cnt[vec[0]];i++){
            if(s[i] == vec[0]) continue;
            mp[{s[i], vec[0]}] += 1;
            res += 1;
        }
        for(int i=cnt[vec[0]]+1;i<=cnt[vec[0]]+cnt[vec[1]];i++){
            if(s[i] == vec[1]) continue;
            if(mp[{vec[1], s[i]}] > 0) mp[{vec[1], s[i]}] -= 1;
            else {
                res += 1;
                mp[{s[i], vec[1]}] += 1;
            }
        }
        for(int i=cnt[vec[0]]+cnt[vec[1]]+1;i<=cnt[vec[0]]+cnt[vec[1]]+cnt[vec[2]];i++){
            if(s[i] == vec[2]) continue;
            if(mp[{vec[2], s[i]}] > 0) mp[{vec[2], s[i]}] -= 1;
            else {
                res += 1;
                mp[{s[i], vec[2]}] += 1;
            }
        }
        int f = 0;
        for(auto &a : vec) 
            for(auto &b : vec)
                if(a == b) continue;
                else if(mp[{a,b}] > 0) f = max(f, mp[{a,b}]);
        res -= f;
        ans = min(ans, res);
    }while(next_permutation(vec.begin(), vec.end()));
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
int n,m,k;
string s;
unordered_map<int,int> memo[20];

int f(int i,int mul,int isLimit,int isNum){
    if(i == m) return mul <= k && isNum;
    if(!isLimit && isNum && memo[i].count(mul)) return memo[i][mul];
    
    int res = 0;
    if(!isNum) res += f(i+1,mul,false,false);

    int up = isLimit ? s[i] - '0' : 9;
    for(int d=isNum?0:1;d<=up;d++)
        res += f(i+1,mul*d,isLimit&(d==up),true);

    if(!isLimit && isNum) memo[i][mul] = res;
    return res;
}

void solve(){
    cin>>n>>k;
    s = to_string(n); m = s.length();
    cout << f(0,1,true,false) << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}

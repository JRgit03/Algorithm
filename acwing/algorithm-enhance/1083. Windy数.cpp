#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 20;
int n;
string s;
int memo[N][N];

int f(int i,int pre,int isLimit,int isNum){
    if(i == n) return isNum;
    if(!isLimit && isNum && memo[i][pre] != -1) return memo[i][pre];
    
    int res = 0;
    if(!isNum) res = f(i+1,pre,0,0);
    
    int up = isLimit ? s[i] - '0' : 9;
    for(int d=1-isNum;d<=up;d++)
        if(abs(pre - d) >= 2)
            res += f(i+1,d,isLimit&(d==up),1);
    
    if(!isLimit && isNum) memo[i][pre] = res;
    return res;
} 

void solve(){
    int a,b; cin>>a>>b;
    s = to_string(b); n = s.length(); memset(memo,-1,sizeof memo); int ansr = f(0,11,1,0);
    s = to_string(a); n = s.length(); memset(memo,-1,sizeof memo); int ansl = f(0,11,1,0);
    auto check = [&](int a){
        string s = to_string(a);
        int f = 1; 
        for(int i=1;i<s.length();i++)
            f &= (abs(s[i] - s[i-1]) >= 2);
        return f;
    };
    cout << ansr - ansl + check(a) << "\n";
}

int main(){
    IOS; solve();
    return 0;
}

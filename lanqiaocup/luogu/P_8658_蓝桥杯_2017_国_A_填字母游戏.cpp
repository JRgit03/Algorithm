#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

int n;
string s;
map<string, int> memo;

int dfs(){
    if(memo.count(s)) return memo[s];
    if(s.find("LOL") != -1) return -1; // 当前局面如果s包含LOL则自己必败对手必胜
    if(s.find("*") == -1) return 0; // 没有可填空位 则 必然平局

    int tie = 0, re;
    for(int i=0;i<n;i++){
        if(s[i] == '*'){ // 枚举填入的字符L/O
            s[i] = 'L';
            re = dfs();
            s[i] = '*';
            if(re == -1) return memo[s] = 1; // 对手必败则自己必胜
            else if(re == 0) tie = 1; // 存在平局的局面

            s[i] = 'O';
            re = dfs();
            s[i] = '*';
            if(re == -1) return memo[s] = 1;
            else if(re == 0) tie = 1;
        }
    }

    // 能平局则平局,否则必败（必胜的局面直接优先return了）
    if(tie) return memo[s] = 0;
    return memo[s] = -1;
}

void solve(){
    memo.clear();
    cin>>s; n = s.length();
    
    if(s.length() < 3){
        cout << 0 << "\n";
        return;
    }

    cout << dfs() << "\n";
    return;
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

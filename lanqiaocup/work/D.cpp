#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 200 + 10;
int n;
int ans2;
int ans;
string s[N];

void calc(int x,int y,char c1,char c2){
    int res = ans2;
    for(int i=1;i<=n;i++){
        int len1 = s[i].length(), len2 = s[x].length();
        if(i == x) continue;
        for(int k=0;k<min(len1,len2);k++){
            if(s[i][k] == s[x][k]) res--;
            else break;
        }
    }
    s[x][y] = c2;
    for(int i=1;i<=n;i++){
        int len1 = s[i].length(), len2 = s[x].length();
        if(i == x) continue;
        for(int k=0;k<min(len1,len2);k++){
            if(s[i][k] == s[x][k]) res++;
            else break;
        }
    }
    s[x][y] = c1;
    ans = max(ans, res);
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int len1 = s[i].length(), len2 = s[j].length();
            for(int k=0;k<min(len1,len2);k++){
                if(s[i][k] == s[j][k]) ans2++;
                else break;
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<s[i].length();j++){
            char c1 = s[i][j];
            for(char c2 = 'a'; c2 <= 'z'; c2++) calc(i,j,c1,c2);
        }
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
} 

/*
3
aab
bbb
abb

5
*/

/*
3
a
a
a

3
*/

/*
3
ab
ab
ac

6
*/



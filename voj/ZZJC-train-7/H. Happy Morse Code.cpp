#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e5 + 10 , Mod = 128;

int f[N]; // f[i] 表示目标字符串完全匹配前i个字母的方案数
bool update[N]; // update[i] 表示目标字符串完全匹配前i个字母的方案数是否大于128

void solve(){
    int n,m;cin>>n>>m;
    memset(f,0,sizeof f);
    memset(update,false,sizeof update);
    f[0] = 1 , update[0] = false;

    map<string,int> cnt;

    for(int i=0;i<m;i++){
        string a,s;cin>>a>>s;
        cnt[s]++;
    }

    string str;cin>>str;str = "?" + str;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5&&i-j+1>=1;j++){
            string zc = str.substr(i-j+1,j);
            if(cnt[zc]){
                //cout << zc << " " << i << " " << j << " " << update[i] << "\n";
                if(f[i-j] * cnt[zc] >= 128) update[i] = true;
                else if(f[i] + f[i-j] * cnt[zc] % Mod >= 128) update[i] = true;
                else if(update[i-j]) update[i] = true;
                //cout << i << " " << j << " " << update[i] << "\n";
                f[i] = (f[i] + f[i-j] * cnt[zc] % Mod) % Mod;
            }
        }
    }
    //cout << f[n] << " " << update[n] << "\n";

    if(!f[n] && !update[n]) cout << "nonono" << "\n";
    else if(f[n]==1 && !update[n]) cout << "happymorsecode" << "\n";
    else cout << "puppymousecat " << f[n] << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}

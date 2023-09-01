#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    string str; cin>>str;
    int n = str.length();
    int len = 0 ,s = 1 , t = 0; // s 最小确保升序的位置 t 最小的非升序位置
    vector<int> f(n+1,0); f[0] = f[1] = 1; // f 状况 0 不确定 1 有序 -1 无序
    for(int i=0;i<n;i++){
        char c = str[i];
        if(c == '+') len++;
        else if(c == '-'){
            if(len>1) f[len] = 0;
            len--;
            s = max(1,min(s,len));
            if(len < t) t = 0;
        }else if(c == '1'){
            if(t || f[len] == -1) {
                cout << "NO" << "\n";
                return;
            }else{
                while(s <= len) f[s++] = 1; s--;
            }
        }else if(c == '0'){
            if(!f[len]) {
                f[len] = -1;
                if(!t) t = len;
            }else if(f[len] == -1) continue;
            else if(f[len] == 1) {
                cout << "NO" << "\n";
                return;
            }
        }
    }
    cout << "YES" << "\n";
    return;
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}

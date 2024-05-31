#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e6 + 10;

int res;

void solve(){
    string s; getline(cin, s); // cout << s << "\n";
    int n = s.length();
    if(s.find("[]") == -1){ // var
        if(s[0] == 'i'){
            for(int i=0;i<n;i++) if(s[i] == '=') {
                res += 4;
            }
        }else if(s[0] == 'l'){
            for(int i=0;i<n;i++) if(s[i] == '=') {
                res += 8;
            }
        }else{
            for(int i=0;i<n;i++){
                if(s[i] == '"'){
                    int j = i + 1;
                    while(j < n && s[j] != '"') {
                        res += 1;
                        j += 1;
                    }
                    i = j;
                }
            }
        }
    }else{ // array
        if(s[0] == 'i'){
            for(int i=0;i<n;i++) {
                if(s[i] == '['){
                    int x = 0, j = i + 1;
                    while(j < n && s[j] != ']'){
                        x = x * 10 + s[j] - '0';
                        j += 1;
                    }
                    i = j;
                    res += x * 4;
                }
            }
        }else{
            for(int i=0;i<n;i++) {
                if(s[i] == '['){
                    int x = 0, j = i + 1;
                    while(j < n && s[j] != ']'){
                        x = x * 10 + s[j] - '0';
                        j += 1;
                    }
                    i = j;
                    res += x * 8;
                }
            }
        }
    }
}

signed main(){
    // IOS;
    int t; cin>>t; getchar(); 
    while(t--) solve();
    int g = 0, m = 0, k = 0, b = 0;
    g = res / 1024 / 1024 / 1024;
    m = res / 1024 / 1024 % 1024;
    k = res / 1024 % 1024;
    b = res % 1024;
    if(g != 0) printf("%lldGB", g);
    if(m != 0) printf("%lldMB", m);
    if(k != 0) printf("%lldKB", k);
    if(b != 0) printf("%lldB", b);
    return 0;
}

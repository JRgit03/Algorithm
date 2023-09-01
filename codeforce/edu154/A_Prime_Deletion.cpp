#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

int primes[110] , cnt;
int st[110];

void init(){
    for(int i=2;i<=100;i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j=0;primes[j] <= 100/i ;j++){
            st[primes[j]*i] = 1;
            if(i % primes[j] == 0)break;
        }
    }    
}

void solve(){
    // cout << st[97] << " " << st[79] << "\n";

    string s; cin>>s;

    // for(int i=0;i<9;i++)
    //     for(int j=i+1;j<9;j++){
    //         if(!st[(s[i] - '0') * 10 + (s[j] - '0')]){
    //             cout << s[i] << s[j] << "\n";
    //             return;
    //         }
    //     }
    // cout << -1 << "\n";

    int i = s.find('9') , j = s.find('7');
    cout << (i < j ? 97 : 79) << "\n";
}

int main(){
    IOS;
    init();
    int t;cin>>t;
    while(t--)solve();
    return 0;
}

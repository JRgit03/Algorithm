#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int n,m,M;

void solve(){
    cin>>n>>m>>M;
    if(n+m<=M){
        cout << "draw" << "\n";return;
    }
    bool f = false;
    map<pair<int,int>,int> mp; // 1表示fx操作的 
    while(n>0 && m>0){
        if(n>=m){
            mp[{n-m,m}] = 1;
            if(n-m+m == M){
               if(!f){
                    cout << "lovely"<<"\n";return;
               }else{
                    cout<<"type-c"<<"\n";return;
               }  
            }
            f = true;
            n -= m;
        }else{
            mp[{n,m-n}] = 2;
            if(n+m-n == M){
                if(!f){
                    cout<<"type-c"<<"\n";return;
                }else{
                    cout<<"lovely"<<"\n";return;
                }
            }
            m -= n;
        }
    }
    cout << "draw" << "\n";return;
}

int main(){
    IOS;
    int t;cin>>t;while(t--)solve();
    return 0;
}

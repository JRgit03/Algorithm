#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
int a,k,q;

signed main(){
    IOS;
    cin>>a>>k>>q; a &= 1 , k &= 1;
    for(int i=0;i<q;i++){
        int l,r; cin>>l>>r;
        if(!a && !k){
            cout << -1 << "\n";
        }else if(a && !k){
            cout << 1 << "\n";
        }else if(!a && k){
            int x = r / 2 - (l - 1) / 2; //奇数
            if(x == r-l+1-x){
                cout << 0 << "\n";
            }else{
                cout << (x > r-l+1-x ? 1 : -1) << "\n";
            }
        }else{
            int x = (r + 1) / 2 - (l - 1 + 1) / 2;
            if(x == r-l+1-x){
                cout << 0 << "\n";
            }else{
                cout << (x > r-l+1-x ? 1 : -1) << "\n";
            }
        }
    }
    return 0;
}

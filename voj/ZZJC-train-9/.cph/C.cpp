#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

int main(){
    IOS;
    int n,m,x;cin>>n>>m>>x;
    int cnt1=0,cnt2=0;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp; cnt1 += (tmp >= x);
    }
    for(int i=1;i<=m;i++){
        cin>>tmp; cnt2 += (tmp <= x);
    }
    cout << cnt1 + cnt2 << "\n";
    return 0;
}

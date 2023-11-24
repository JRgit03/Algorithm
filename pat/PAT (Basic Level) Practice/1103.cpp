#include <bits/stdc++.h>
#define int long long 
using namespace std;
map<int,int> mp;
signed main(){
    for(int i=1;i<=1000;i++){
        int y = i * i + (i - 1) * (i - 1);
        mp[y * y] = i;
    }
    int m,n,ok=0; cin>>m>>n;
    for(int i=m;i<=n;i++){
        int val = i * i * i - (i - 1) * (i - 1) * (i - 1);
        if(mp.count(val) && i != mp[val]){ // 题目要求a != c 另一个整数
            ok = 1;
            cout << i << " " << mp[val] << "\n";
        }
    }
    if(!ok) cout << "No Solution" << "\n";
    return 0;
}

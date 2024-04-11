#include <bits/stdc++.h>
using namespace std;

void ask(int x){
    cout << "?" << " " << x << "\n";
}

void put(int x){
    cout << "!" << " " << x << "\n";
}

void solve(){
    int n; cin>>n;
    int pre = 0, c;
    for(int i=1;i<=20;i++){
        ask(i);
        cin>>c;
        if(c == pre) {
            put(i);
            return;
        }
        pre = c;
    }
    int l = 21, r = n;
    while(l < r){
        int mid = (l + r) >> 1;
        ask(mid);
        cin>>c;
        if(c == pre){
            put(mid);
            return;
        }else if(c > pre){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
        pre = c;
    }
    put(r);
    return;
}

signed main(){
    solve();
    return 0;
} 

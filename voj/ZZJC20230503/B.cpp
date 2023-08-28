#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    deque<int> q;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x&1)q.push_back(x);
        else q.push_front(x);
    }
    int suma = 0 , sumb = 0 , flag = false;
    while(q.size()){
        int x = q.front(); q.pop_front();
        if(!(x&1)) suma+=x;
        else sumb+=x;
        if(sumb >= suma) flag = true;
    }
    cout << (flag ? "NO" : "YES") << "\n";
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}

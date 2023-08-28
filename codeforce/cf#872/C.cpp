#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;cin>>n>>m;
    int lcnt=0,rcnt=0;
    set<int> s;
    while(n--){
        int x;cin>>x;
        if(x==-1)lcnt++;
        else if(x==-2)rcnt++;
        else s.insert(x);
    }
    if(!s.size()){
        cout << max(lcnt,rcnt) << "\n";return;
    }

    cout << min((int)s.size() + lcnt + rcnt , m) << "\n";  
}

int main(){int t;cin>>t;while(t--)solve();return 0;}

#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(){
    int q; cin>>q;
    multiset<int> ls,rs;
    while(q--){
        char op;int l,r; cin>>op>>l>>r;
        if(op == '+') ls.insert(l) , rs.insert(r);
        else ls.erase(ls.lower_bound(l)), rs.erase(rs.lower_bound(r));
        int gte = *rs.begin() + 1;
        cout << (ls.lower_bound(gte) != ls.end() ? "YES" : "NO") << "\n";
    }
}

int main(){
    IOS; solve();
    return 0;
}

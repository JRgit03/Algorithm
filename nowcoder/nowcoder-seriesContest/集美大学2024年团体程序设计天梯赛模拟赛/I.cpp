#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 10;
typedef pair<char,int> PCI;
int n,m;
deque<PCI> q[N]; // right~top

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        char c; cin>>c; //cerr << c << " " << i << "\n";
        q[i].push_back({c, i});
    }
    while(m--){
        int op,x,y; cin>>op>>x;
        if(op == 1){ // x right~left
            cin>>y;
            while(q[x].size()) {
                q[y].push_back(q[x].back()); q[x].pop_back();
            }
        }else if(op == 2){ // x left~right
            cin>>y;
            while(q[x].size()) {
                q[y].push_back(q[x].front()); q[x].pop_front();
            }
        }else{ // back
            vector<PCI> vec;
            while(q[x].size()) {
                vec.push_back(q[x].back()); //cerr << q[x].back().first << "\n";
                q[x].pop_back();
            }
            // cerr << "del " << x << "\n";
            // for(auto [c, id] : vec) cerr << c << " " << id << "\n"; 
            for(auto [c, id] : vec) q[id].push_back({c,id});
        }
    }
    for(int i=1;i<=n;i++){
        stack<char> stk;
        vector<string> res;
        // cerr << "===" << " " << i << "\n";
        while(q[i].size()){
            auto [c, id] = q[i].front(); q[i].pop_front(); 
            // cerr << c << "\n"; 
            if(c != ')') stk.push(c);
            else{
                string s = "";
                while(stk.size() && stk.top() != '('){
                    s += stk.top(); stk.pop();
                }
                if(stk.size() && stk.top() == '(') {
                    stk.pop();
                    if(s.length() != 0) {
                        reverse(s.begin(), s.end());
                        res.push_back(s);
                    }
                } else stk.push(c);
            }
        }
        string s = "";
        while(stk.size() && stk.top() != '(' && stk.top() != ')') {
            s += stk.top(); stk.pop();
        }
        if(s.length() != 0) {
            reverse(s.begin(), s.end());
            res.push_back(s);
        }
        if(stk.size() == 0) {
            cout << res.size(); 
            for(auto &x : res) cout << " " << x; cout << "\n";
        }else{
            cout << -1 << "\n";
        }
    }
}

signed main(){
    solve();
    return 0;
}

#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 1048576 + 10;
int ans[N];

int main(){
    IOS;
    int n,m; cin>>n>>m;
    queue<int> q; q.push(1);
    for(int i=0;i<n;i++){
        queue<int> tmp; int cnt = 0;
        while(q.size()){
            int t = q.front(); q.pop();
            ans[t] = ++cnt;
            tmp.push(t<<1); tmp.push(t<<1|1);
        }
        q = tmp;
    }
    for(int i=0;i<m;i++){
        string s; cin>>s; int x = 1;
        for(auto &c : s){
            x <<= 1;
            if(c == 'R') x += 1;
        }
        cout << ans[x] << "\n";
    }
    return 0;
}

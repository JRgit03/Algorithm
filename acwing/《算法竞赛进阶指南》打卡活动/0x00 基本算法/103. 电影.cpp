#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n,m;
int b[maxn],c[maxn];
map<int,int> cnt; 

struct Node{
    int id;
    int v1,v2;

    bool operator < (const Node& o) const {
        return (v1 != o.v1 ? v1 > o.v1 : v2 > o.v2); 
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        int x; cin>>x;
        cnt[x] += 1;
    }
    cin>>m;
    vector<Node> vec(m);
    for(int i=0;i<m;i++) cin>>b[i];
    for(int i=0;i<m;i++) cin>>c[i];
    for(int i=0;i<m;i++) vec[i] = {i,cnt[b[i]],cnt[c[i]]};
    sort(vec.begin(),vec.end());
    cout << vec[0].id + 1 << "\n";
    return 0;
}

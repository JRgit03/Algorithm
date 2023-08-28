#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10 , M = 1e5 + 10;
int n,m;
int p[N];

struct Edge{
    int a,b,w;
    bool operator < (const Edge &t) const {
        return w < t.w;
    }
}edges[M];

int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}

int kru(){
    int res = -1 , cnt = 1;
    sort(edges,edges+m);
    for(int i=1;i<=n;i++) p[i] = i;

    for(int i=0;i<m;i++){
        auto [a,b,w] = edges[i];
        int pa = find(a) , pb = find(b);
        if(pa!=pb){
            p[pa] = pb;
            res = max(res,w);
            cnt++;
        }
    }
    if(cnt!=n) res=-1;
    return res;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,w;cin>>a>>b>>w;
        edges[i] = {a,b,w};
    } 
    cout << kru() << "\n";
    return 0;
}

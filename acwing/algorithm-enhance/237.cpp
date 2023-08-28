#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int p[N];

struct Node{
    int a,b;
    int f;
};

unordered_map<int,int> mp;
int idx;

int maping(int x){ //离散化
    if(mp[x]) return mp[x];
    mp[x] = ++idx; return idx;
}

int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}

void merge(int a,int b){
    int pa = find(a) , pb = find(b);
    if(pa!=pb){
        p[pa] = pb;
    }
}

void solve(){
    int n;scanf("%d",&n);
    mp.clear(); idx = 0;
    for(int i=1;i<=2*n;i++) p[i] = i;
    vector<Node> ineq;
    for(int i=1;i<=n;i++){
        int a,b,f;cin>>a>>b>>f;
        a = maping(a) , b = maping(b);
        if(f) merge(a,b);
        else ineq.push_back({a,b,f});
    }
    for(auto [a,b,f] : ineq){
        if(find(a)==find(b)){
            printf("NO\n");return;
        }
    }
    printf("YES\n");return;
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int n,m,q;
int p[N];

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

int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) p[i]=i;
    while(m--){int a,b;cin>>a>>b;merge(a,b);}
    while(q--){
        int a,b;cin>>a>>b;
        cout << (find(a)==find(b) ? "Yes" : "No") << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n,m;
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
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i] = i;
    while(m--){
        int op,x,y;cin>>op>>x>>y;
        if(op==1) merge(x,y);
        else {
            cout << (find(x) == find(y) ? "Y" : "N") << "\n";
        }
    }
    return 0;
}

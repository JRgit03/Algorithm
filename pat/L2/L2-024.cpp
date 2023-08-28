#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n;
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
    cin>>n;
    for(int i=1;i<N;i++) p[i] = i;
    set<int> sz;
    for(int i=1;i<=n;i++){
        int k,a;cin>>k>>a;k--;sz.insert(a);
        while(k--){
            int b;cin>>b;sz.insert(b);
            merge(a,b);
        }
    }

    int cnt = 0;
    for(auto x : sz) cnt += (x == find(x));

    //for(int i=1;i<=10;i++) cout << find(i) << " \n"[i==10];
    
    cout << (int)sz.size() << " " << cnt << "\n";
    int q;cin>>q;

    while(q--){
        int a,b;cin>>a>>b;
        int pa = find(a) , pb = find(b);
        //cout << pa << " " << pb << "\n";
        if(pa==pb)puts("Y");
        else puts("N");
    }
    return 0;
}

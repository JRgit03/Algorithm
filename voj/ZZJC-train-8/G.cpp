#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef pair<int,int> PII;
const int N = 5e5 + 10;
int n;
int idx;
map<PII,int> mp;

int p[N];
int sz[N] , sz2[N];

int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}

int dx[] = {-1,0,1,1,0,-1};
int dy[] = {1,1,0,-1,-1,0};

void merge(int a,int b){
    int pa = find(a) , pb = find(b);
    p[pa] = pb;
    sz[pb] += sz[pa];
    sz2[pb] += sz2[pa] + 1;
}

int query(int x,int y){
    return sz[find(mp[{x,y}])]*6 - sz2[find(mp[{x,y}])]*2;
}

int main(){
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++) p[i] = i , sz[i] = 1 , sz2[i] = 0;
    for(int i=1;i<=n;i++){
        int op,x,y;cin>>op>>x>>y;
        if(op==1){
            if(!mp[{x,y}]) mp[{x,y}] = ++idx;
            for(int i=0;i<6;i++){
                int u = x + dx[i] , v = y + dy[i];
                if(mp[{u,v}]) {
                    // cout << x << " " << y << " " << u << " " << v << "\n";
                    merge(mp[{u,v}],mp[{x,y}]);
                }
            }
        }else{
            cout << query(x,y) << "\n";
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 5e5 + 10;
typedef pair<int,int> PII;
int n;
int p[N],sz[N];

int find(int x){
    if(p[x]!=x) return p[x] = find(p[x]);
    return p[x];
}

map<PII,int> mp; int idx;

int dx[] = {0,1,1,0,-1,-1} , dy[] = {1,0,-1,-1,0,1};

int main(){
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++) p[i] = i , sz[i] = 6;
    for(int i=0;i<n;i++){
        int op,x,y;cin>>op>>x>>y;
        if(!mp[{x,y}]) mp[{x,y}] = ++idx;
        if(op==1){
            for(int i=0;i<6;i++){
                int u = x + dx[i] , v = y + dy[i];
                if(mp[{u,v}]){
                    int pa = find(mp[{x,y}]) , pb = find(mp[{u,v}]);
                    if(pa!=pb){
                        p[pa] = pb;
                        sz[pb] += sz[pa] - 2;
                    }else sz[pb] -= 2;  //已经在同一连通块内
                }
            }
        }else{
            cout << sz[find(mp[{x,y}])] << "\n";
        }
    }
    return 0;
}

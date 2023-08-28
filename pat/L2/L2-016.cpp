#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;

int vis[N];
bool sexs[N]; //true - man
vector<int> h[N];

void dfs(int u,int cnt,bool &f){
    if(cnt>=4) return;
    
    for(auto &v : h[u]){
        if(!vis[v]){
            vis[v] = true;
            dfs(v,cnt+1,f);
        }else{
            f = true;return;
        }
    }
}

int main(){
	cin>>n;
    for(int i=1;i<=n;i++){
        int id,fid,mid;char sex;
        cin>>id>>sex>>fid>>mid;
        sexs[id] = (sex == 'M');
        if(fid!=-1) h[id].push_back(fid) , sexs[fid] = true;
        if(mid!=-1) h[id].push_back(mid) , sexs[mid] = false;
    }
    int k;cin>>k;
    while(k--){
        int a,b;cin>>a>>b;
        if(sexs[a] == sexs[b]){
            cout << "Never Mind" << "\n";
        }else{
            memset(vis,false,sizeof vis);
            bool f = false;
            vis[a] = true , vis[b]  = true;
            dfs(a,0,f);
            dfs(b,0,f);
            if(!f) cout << "Yes" << "\n";
            else cout << "No" << "\n";
        }
    }
	return 0;
}
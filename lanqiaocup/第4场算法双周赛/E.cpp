#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef pair<int,int> PII;
int n,m,q;
int s[maxn],b[maxn];
void add(int l,int r){b[l]+=1,b[r+1]-=1;}
int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++) cin>>s[i];
    vector<PII> vec[m+1],all;
    while(q--){
        int p,k; cin>>p>>k;
        vec[p].push_back({k,min(n,k+s[p]-1)});
    }
    for(int i=1;i<=m;i++){
        if(vec[i].size()){
            sort(vec[i].begin(),vec[i].end());
            int st = vec[i][0].first, ed = vec[i][0].second;
            for(int j=1;j<vec[i].size();j++){
                auto [l,r] = vec[i][j];
                if(l <= ed){
                    ed = max(ed, r);
                }else{
                    all.push_back({st,ed});
                    st = l, ed = r;
                }
            }
            if(st != 0) all.push_back({st,ed});
        }
    }
    for(auto [l,r] : all) add(l,r);
    for(int i=1;i<=n;i++) {
        b[i] += b[i-1];
        cout << b[i] << " ";
    }
    return 0;
}

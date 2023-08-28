#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,m;
int cur;
vector<int> h[N];
map<int,int> d;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int x;cin>>x;h[i].push_back(x);
        }
    }
    cur = 1;
    while(m--){
        int op,x;cin>>op>>x;
        if(!op){
            cur = h[cur][x-1];
        }else if(op==1){
            d[x] = cur;
            cout << cur << "\n";
        }else if(op==2){
            cur = d[x];
        }
    }
    cout << cur << "\n";
    return 0;
}

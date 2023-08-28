#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n;
int w[N],f[N];
int res=-1,st,ed,l=1;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];   
    for(int i=1;i<=n;i++){
        f[i] = max(w[i],f[i-1]+w[i]);
        if(f[i-1]<0) l = i;
        if(f[i] > res){
            res = f[i];
            st = l , ed = i;
        }
    }
    if(res < 0) res = 0 , st = 1 , ed = n;
    cout << res << " " << w[st] << " " << w[ed] << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10;
int n,m;
int id[N],l[N],r[N];
int a[N],b[N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
    for(int i=1;i<=m;i++) cin>>a[i]>>b[i];
    iota(id+1,id+1+n,1);
    sort(id+1,id+1+n,[&](int i,int j){
        return (l[i] != l[j] ? l[i] > l[j] : r[i] > r[j]);
    });
    int ans = 0;
    for(int i=1;i<=n;i++){
        int k = -1;
        for(int j=1;j<=m;j++)
            if(a[j] > l[id[i]] && a[j] < r[id[i]] && b[j])
                if(k == -1 || a[j] > a[k]){
                    k = j;
        if(k != -1){
            ans += 1;
            b[k] -= 1;
        }
    }
    cout << ans << "\n";
    return 0;
}

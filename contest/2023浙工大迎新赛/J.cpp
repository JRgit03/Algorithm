#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int n,m,q;
bitset<maxn> d[maxn]; 

int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            int to; scanf("%d",&to);
            d[j][to] = 1;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)  
            if(d[j][i]) 
                d[j] |= d[i];  
    while(q--){
        int a,b; scanf("%d%d",&a,&b);
        if(d[a][b] || a == b) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

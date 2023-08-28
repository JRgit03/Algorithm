#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10 , M = N << 1;
int n;
int ans;
int h[N] , e[M] , ne[M] , w[M] , idx;

void add(int a,int b,int c) {
    e[idx] = b , w[idx] = c , ne[idx] = h[a] , h[a] = idx++;
}

int dfs(int u , int fa){
    int dist = 0;
    int d1 , d2 ;
    d1 = d2 = 0; 
    for(int i=h[u];~i;i=ne[i]){
        int j = e[i];
        if(j==fa) continue;
        int d = dfs(j,u) + w[i] ;
        dist = max(d , dist);
        if(d > d1) d2 = d1 , d1 = d; //最长路更新
        else if(d > d2) d2 = d; //次长路更新
    }
    ans = max(ans , d1 + d2);
    return dist;
}

int main(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;i++){
        int a,b,c;cin>>a>>b>>c;
        add(a,b,c) , add(b,a,c);
    }
    dfs(1,-1);
    cout << ans << endl;
    return 0;
}

作者：R_34
链接：https://www.acwing.com/activity/content/code/content/5070267/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
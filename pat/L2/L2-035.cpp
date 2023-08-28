#include <bits/stdc++.h>
using namespace std;
const int N = 33;
int n;
int tr[N],cnt;
int w[N];

void build(int u){ //按照后序遍历dfs 左右根
    if(u*2<=n)build(u*2);
    if(u*2+1<=n)build(u*2+1);
    tr[u] = w[++cnt];
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i];
    build(1);
    cout<<tr[1];
    for(int i=2;i<=n;i++)cout<<" "<<tr[i];
    return 0;
}

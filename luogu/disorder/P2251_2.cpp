#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,m;
int w[N],q[N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    int hh=1,tt=0;
    for(int i=1;i<=n;i++){
        while(hh<=tt && i - q[hh] >= m) hh++;
        while(hh<=tt && w[q[tt]] >= w[i]) tt--;
        q[++tt] = i;
        if(i>=m)printf("%d\n",w[q[hh]]);
    }       
    return 0;
}

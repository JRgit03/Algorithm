#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
typedef pair<int,int> PII;
int n;
int a[N],ans[N];
PII stk[N]; int tt;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=n;i>=1;i--){
        while(tt>0 && stk[tt].first <= a[i]) tt--;
        ans[i] = stk[tt].second;
        stk[++tt] = {a[i],i};
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}

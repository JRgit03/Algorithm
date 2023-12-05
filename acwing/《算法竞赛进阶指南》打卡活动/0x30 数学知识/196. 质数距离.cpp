#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int l,r;
    while(cin>>l>>r){
        int n = sqrt(r);
        vector<int> primes(n+1),st(n+1),vis(1e6+10); int cnt = 0;
        for(int i=2;i<=n;i++){
            if(!st[i]) primes[cnt++] = i;
            for(int j=0;primes[j]<=n/i;j++){
                st[primes[j]*i] = 1;
                if(i % primes[j] == 0) break;
            }
        }
        for(int i=0;i<cnt;i++){
            int p = primes[i];
            for(int j = max(2*p,(l+p-1)/p*p); j <= r; j += p){
            	vis[j-l] = 1;
            }
        }
        int maxx = -1, minn = INT_MAX, pre = -1;
        pair<int,int> ANS1,ANS2;
        for(int i=l;i<=r;i++){
            if(vis[i-l] || i == 1) continue;
            if(pre == -1)  pre = i;
            else {
                if(i - pre + 1 > maxx){
                    maxx = i - pre + 1;
                    ANS2 = {pre,i};
                }
                if(i - pre + 1 < minn){
                    minn = i - pre + 1;
                    ANS1 = {pre,i};
                }
                pre = i;
            }
        }
        if(maxx == -1 && minn == INT_MAX){
            printf("There are no adjacent primes.\n");
        }else{
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",ANS1.first,ANS1.second,ANS2.first,ANS2.second);
        }
    }
    return 0;
}
// vis离散化数组 

#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e5 + 10;

int res;
int n,cur,dmg;

int hp[N],dps[N],d[N];
int b[N];

void add(int l,int r,int c){
    b[l]+=c,b[r+1]-=c;
}

signed main(){
    IOS;
    cin>>n>>cur>>dmg;
    for(int i=1;i<=n;i++)   
        cin>>hp[i]>>dps[i]>>d[i];
    for(int i=1;i<=n;i++)
        add(max(i-d[i],1LL),i,dps[i]);
    for(int i=1;i<=n;i++)
        b[i] += b[i-1];
    
    for(int i=1;i<=n;i++){
        int t1 = (hp[i] + dmg -1) / dmg; //塔可以受到多少次攻击
        int t2 = (cur + b[i] - 1) / b[i]; //玩家可以攻击多少次
        // cout << t1 << " " << t2 << "\n";
        if(t1 <= t2){
            cur -= t1 * b[i];
            res++;
        }else{
            break;
        }
        if(cur<=0) break;
    }
    cout << res << "\n";
    return 0;
}

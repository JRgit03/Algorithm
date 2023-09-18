#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;
const int N = 10;
int n,KMAX;
int f[N][1<<N][N*N]; // f[i,j,k] 前i-1行已经放好 且第i行的状态为j 放了k个皇后的合法方案

int cnt;
vector<int> st;
map<int,int> mp;

bool check(int st){
    return !(st & (st >> 1));
}

signed main(){
    IOS;
    cin>>n>>KMAX;
    for(int i=0;i<1<<n;i++)
        if(check(i)){
            st.push_back(i);
            mp[i] = __builtin_popcount(i);
        }

    cnt = mp.size();
    for(int j=0;j<cnt;j++) f[1][st[j]][mp[st[j]]] = 1;

    for(int i=2;i<=n;i++) //枚举行数
        for(int j=0;j<=KMAX;j++){ //枚举国王个数
            for(int st1=0;st1<cnt;st1++){ //枚举上一行
                for(int st2=0;st2<cnt;st2++){ //枚举当前行
                    int pre = st[st1] , cur = st[st2];
                    if(pre & cur) continue;
                    if(pre & (cur << 1)) continue;
                    if(pre & (cur >> 1)) continue;
                    if(j-mp[cur] >= 0) f[i][cur][j] += f[i-1][pre][j-mp[cur]];
                }
            }
        }

    int ans = 0;
    for(int i=0;i<cnt;i++) ans += f[n][st[i]][KMAX];
    cout << ans << "\n";
    return 0;
}

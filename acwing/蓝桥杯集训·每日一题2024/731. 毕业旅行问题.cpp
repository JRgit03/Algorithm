#include <bits/stdc++.h>
using namespace std;
int n;
int w[21][21];
int dp[1 << 20][21]; // dp[i,j] 当前访问的点集为i,且终点为j的最小代价

template <typename T>
inline void read(T &f)
{
    f=1;
    T x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    f*=x;
}
template <typename T>
inline void print(T x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}

void solve(){
    cin>>n;
    memset(dp, 0x3f, sizeof dp);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            read(w[i][j]);
    dp[1][0] = 0;
    for(int i=1;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(!((i >> j) & 1)) continue;
            for(int k=0;k<n;k++){
                if(!((i >> k) & 1)) continue;
                dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + w[k][j]);
            }
        }
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++) ans = min(ans, dp[(1<<n) - 1][i] + w[i][0]);
    print(ans);
}

signed main(){
    solve();
    return 0;
}

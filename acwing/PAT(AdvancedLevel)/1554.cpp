#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10 , M = 1e2 + 10;
int n,m;
int a[N];
bool f[N][M]; //f[i,j]表示前i件物品且体积为j的方案是否存在

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n,greater<int>());

    f[0][0] = true;
    for(int i=1;i<=n;i++)   
        for(int j=0;j<=m;j++)
        {
            f[i][j] = f[i-1][j];
            if(j-a[i]>=0) f[i][j] = f[i][j] | f[i-1][j-a[i]];
        }
    if(!f[n][m]) cout << "No Solution" << "\n";
    else{
        int j = m;
        for(int i=n;i>=1;i--){ //从前往后找 保证了ans序列字典序最小
            if(j-a[i]>=0 && (f[i][j] & f[i-1][j-a[i]]))
            {
                cout << a[i] << " ";
                j -= a[i];
            }
        }
        cout << "\n";
    }
    return 0;
}

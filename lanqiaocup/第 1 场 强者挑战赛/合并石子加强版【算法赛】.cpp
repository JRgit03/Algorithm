/**
 * 诈骗题 手玩样例 发现合并方式并不影响最终的答案
 * eg: a1 a2 a3
 * 1) (a1 a2) a3 => (a1 a2 a3)  cost = a1 * a2 + (a1 + a2) * a3 = a1a2 + a1a3 + a2a3 
 * 2) a1 (a2 a3) => (a1 a2 a3)  cost = a2 * a3 + (a2 + a3) * a1 = a1a2 + a1a3 + a2a3 
 */
#include <bits/stdc++.h>
using namespace std;

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

int main(){
    int n; cin>>n;
    vector<int> a(n); for(int i=0;i<n;i++) read(a[i]);
    __int128 ans = 0,pre = 0;
    for(int i=0;i<n;i++){
        ans += pre * a[i];
        pre += a[i];
    }
    print(ans);
    return 0;
}

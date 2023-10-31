#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int T;
int d[N<<1];
char str[N],s[N<<1];

int init(){
    // abcb -? $#a#b#c#b#?
    int n = strlen(str);
    int m = 0;
    s[m]='$'; s[++m]='#';
    for (int i=0;i<n;i++){
        s[++m]=str[i];
        s[++m]='#';
    }
    s[m+1]='?';
    return m; // m = n << 1 + 1
}

int Manacher(){
    int len=init(),M=1,R=1,ans=-1;
    for (int i=1;i<len;i++){
        d[i] = i < R ? min(d[M*2-i] ,R-i) : 1;
        while (s[i - d[i]] == s[i + d[i]]) d[i]++;
        if (i+d[i] > R){
            M = i , R = i+d[i];
        }
        ans = max(ans ,d[i]-1);
    }
    return ans;
}

void solve(){
    init();
    printf("Case %d: %d\n",++T,Manacher());
}

int main(){
    while(~scanf("%s",str)){
        if(str[0] == 'E' && str[1] == 'N' && str[2] == 'D')break;
        solve();
    }
    return 0;
}

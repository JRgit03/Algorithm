/**
 *  线性时间内解决最长回文串
 *  https://www.luogu.com.cn/problem/P3805
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1.1e7 + 10;
int d[N<<1];
char s[N<<1],str[N];

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
int main(){
    scanf("%s",str);
    printf("%d",Manacher());
    return 0;
}
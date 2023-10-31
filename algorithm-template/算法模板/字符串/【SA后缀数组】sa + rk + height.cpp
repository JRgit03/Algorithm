/**
 * 后缀数组的应用 以最长公共子串为例
 * LCS - Longest Common Substring 最长公共子串
 * https://www.luogu.com.cn/problem/SP1811 
 */ 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char s[N]; //从0号为开始
int sa[N]; //后缀数组 排第i的后缀子串在原串的sa[i]位置
int rk[N]; //名次数组 第i个后缀子串排rk[i]位
int tmp[N+1]; //临时数组 计算sa使用
int height[N]; // height[i]表示sa[i-1]和sa[i]的最长公共前缀长度
int n,m,k;

bool comp_sa(int i,int j){
    if(rk[i] != rk[j]) return rk[i] < rk[j];
    int ri = i + k <= n ? rk[i+k] : -1;
    int rj = j + k <= n ? rk[j+k] : -1;
    return ri < rj;
}

void calc_sa(){
    for(int i=0;i<=n;i++){
        rk[i] = s[i]; 
        sa[i] = i;
    }
    for(k=1;k<=n;k<<=1){
        sort(sa,sa+n,comp_sa);
        tmp[sa[0]] = 0;
        for(int i=0;i<n;i++)
            tmp[sa[i+1]] = tmp[sa[i]] + (comp_sa(sa[i],sa[i+1]) ? 1 : 0);
        for(int i=0;i<n;i++) rk[i] = tmp[i];
        //for(int i=0;i<n;i++) cout << rk[i] << " "; cout << "\n";
    }
}

int cnt[N],t1[N],t2[N];

void calc_sa2(){
    int m = 127;
    int i,*x = t1, *y = t2;
    for(int i=0;i<m;i++) cnt[i] = 0;
    for(int i=0;i<n;i++) cnt[x[i] = s[i]]++;
    for(int i=0;i<m;i++) cnt[i] += cnt[i-1];
    for(int i=n-1;i>=0;i--) sa[--cnt[x[i]]] = i;
    for(int k=1;k<=n;k=k*2){
        int p = 0;
        for(int i=n-k;i<n;i++) y[p++] = i;
        for(int i=0;i<n;i++) if(sa[i] >= k) y[p++] = sa[i] - k;
        for(int i=0;i<m;i++) cnt[i] = 0;
        for(int i=0;i<n;i++) cnt[x[y[i]]]++;
        for(int i=0;i<m;i++) cnt[i] += cnt[i-1];
        for(int i=n-1;i>=0;i--) sa[--cnt[x[y[i]]]] = y[i];
        swap(x,y);
        p = 1; x[sa[0]] = 0;
        for(int i=1;i<n;i++) 
            x[sa[i]] = y[sa[i-1]] == y[sa[i]] && y[sa[i-1] + k] == y[sa[i] + k] ? p-1 : p++;
        if(p>=n) break;
        m = p;
    }
}  

void getheight(int n){
    int i,j,k=0;
    for(i=0;i<n;i++) rk[sa[i]] = i;
    for(i=0;i<n;i++){
        if(k) k--;
        int j = sa[rk[i]-1];
        while(s[i+k] == s[j+k]) k++;
        height[rk[i]] = k;
    }
}

int main(){
    scanf("%s",s); m = strlen(s);
    s[m] = '$'; scanf("%s",s+m+1); n = strlen(s);
    calc_sa();
    getheight(n);
    int ans = 0;
    for(int i=1;i<n;i++)
        if((sa[i-1] < m && sa[i] > m) || (sa[i] < m && sa[i-1] > m))
            ans = max(ans,height[i]);
    cout << ans << "\n";
    return 0;
}

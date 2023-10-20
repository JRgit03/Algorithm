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

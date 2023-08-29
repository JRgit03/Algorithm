/**
 * KMP核心思想：在每次匹配失败时,把p串往后移至下一次可以和前面部分匹配的位置
 * https://www.luogu.com.cn/problem/P3375
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e6 + 10;
int n,m; 
string s,p; // s 匹配串 p 模式串
int ne[N]; //ne数组含义：模式串中前缀和后缀的最长匹配长度

int main(){
    IOS;
    cin>>s>>p; n = s.length() , m = p.length();
    s = "?" + s , p = "?" + p;
    // 求模式串的ne数组
    for(int i=2,j=0;i<=m;i++){
        while(j && p[i] != p[j+1]) j = ne[j];
        if(p[i] == p[j+1]) j++;
        ne[i] = j;
    }
    // 匹配
    for(int i=1,j=0;i<=n;i++){
        while(j && s[i] != p[j+1]) j = ne[j];
        if(s[i] == p[j+1]) j++;
        if(j == m){
            j = ne[j];
            // 匹配成功后的逻辑
            cout << i - m + 1 << "\n";
        }
    }
    // 数组ne数组
    for(int i=1;i<=m;i++) cout << ne[i] << " ";
    return 0;
}

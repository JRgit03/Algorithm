/**
 * 判断s是不是t的循环同构串
 * 循环同构串：s[i...n] + s[1...i-1] = t
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int n,m;
string s,p;
int ne[N];

// 求模式串的ne数组
void getNext(){
    for(int i=2,j=0;i<=m;i++){
        while(j && p[i] != p[j+1]) j = ne[j];
        if(p[i] == p[j+1]) j++;
        ne[i] = j;
    }
}

int main(){
    IOS;
    cin>>n>>s>>p; m = n; n <<= 1; 
    p = "$" + p; s = "?" + s + s;
    for(int i=1;i<=n;i++) s[i] = (islower(s[i]) ? toupper(s[i]) : tolower(s[i]));
    getNext();
    // 匹配
    int ans = INT_MAX;
    for(int i=1,j=0;i<=n;i++){
        while(j && s[i] != p[j+1]) j = ne[j];
        if(s[i] == p[j+1]) j++;
        if(j == m){
            j = ne[j];
            ans = min({ans,i-m,m-(i-m)});
        }
    }
    if(ans == INT_MAX){
        cout << "No" << "\n";
        return 0;
    }
    cout << "Yes" << "\n";
    cout << ans << "\n";
    return 0;
}

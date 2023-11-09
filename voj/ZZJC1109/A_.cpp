#include <bits/stdc++.h>
using namespace std;

int f;
int a[4];
char op[4]; 

// 当前枚举到k层
void dfs(int k,int val){
    // cout << k << " " << val << "\n";
    if(f) return;
    if(k > 4) return;
    if(k == 4){
        if(val == 7){
            f = 1;
            printf("%d%c%d%c%d%c%d=7\n",a[0],op[1],a[1],op[2],a[2],op[3],a[3]);
        }
        return;
    }
    for(int i=0;i<=1;i++){
        op[k] = i ? '-' : '+';
        dfs(k+1,val + (i ? -a[k] : a[k]));
    }
        
}

int main(){
    string s; cin>>s;
    for(int i=0;i<4;i++) a[i] = s[i] - '0';
    dfs(1,a[0]);
    return 0;
}

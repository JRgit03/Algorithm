#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> ans;

// 从数i开始选j个数字
void dfs(int i,int j,int num){
    if(i < j) return;
    if(j == 0){
        ans.push_back(num);
        return;
    }
    for(int k=0;k<i;k++){
        if(num % 10 > k)
         dfs(i,j-1,num*10+k);
    }    
}

signed main(){
    for(int i=1;i<=9;i++) ans.push_back(i);
    for(int j=2;j<=10;j++)
        for(int i=1;i<=9;i++) // 位数
            dfs(i,j-1,i);
    int k; cin>>k;
    cout << ans[k-1] << "\n";
    return 0;
}

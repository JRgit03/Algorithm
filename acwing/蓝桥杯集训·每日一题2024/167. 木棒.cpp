#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n;
int sum,len,maxw;
int w[N];
int st[N]; // st[i] 第i根木棍是否被选

// 当前已经处理好了u根木棍,第u+1木棍已经拼接的长度之和为s,枚举木棍的左端点为start
int dfs(int u,int s,int start){
    if(u * len == sum) return 1;
    if(s == len) return dfs(u + 1, 0, 0);
    
    for(int i=start;i<=n;i++){
        if(st[i]) continue;
        if(s + w[i] <= len){
            st[i] = 1;
            if(dfs(u, s + w[i], i + 1)) return 1;
            st[i] = 0;
            
            // dfs(u, s + w[i], i + 1) 失败

            //如果第一根失败了或者最后一根失败了,就一定失败 
            if (!s) return false; 
            if (s + w[i] == len) return false;

            //如果i失败了,那么长度跟i一样的棍子也一定失败
            int j = i;
            while (j <= n && w[i] == w[j]) j += 1;
            i = j - 1;
        }
    }
    return false;
}

void solve(){
    sum = 0, maxw = 0;
    for(int i=1;i<=n;i++) {
        st[i] = 0;
        cin>>w[i];
        sum += w[i]; 
        maxw = max(maxw, w[i]);
    }
    sort(w + 1, w + 1 + n, greater<int>());
    len = maxw;
    while(true){
        if(sum % len == 0 && dfs(0,0,0)){
            cout << len << "\n";
            return;
        }
        len += 1;
    }
}

signed main(){
    while(cin>>n){
        if(!n) break;
        solve();
    }    
    return 0;
}

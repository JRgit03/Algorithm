#include <bits/stdc++.h>
using namespace std;
int n,k;
string s;

int dp[404][404];

int dfs(int l,int r){
    int &res = dp[l][r];
    if(l > r) res = 0;
    if(res != -1) return res;
    res = min((s[l]=='V')+max(dfs(l+2,r),dfs(l+1,r-1)), (s[r]=='V')+max(dfs(l+1,r-1),dfs(l,r-2)));
    return res;
}

int main(){
    cin>>n>>k>>s; s = "?" + s;
    memset(dp,-1,sizeof dp); 
    int cnt = 0;
    for(int i=1;i<=n;i++) {
        cnt += (s[i] == 'V');
        dp[i][i] = (s[i] == 'V');
    }
    dfs(1,n); 
    int A = 0, B = 0;
    int L = 1, R = n,t = 0;
    while(L <= R){
    	// cout << A << " " << B << " " <<  L << " " << R << " " << dp[L][R] << "\n";
        t += 1;
        if(dp[L][R] == ((s[L] == 'V') + max(dp[L+2][R],dp[L+1][R-1]))){
            A += (s[L] == 'V');
            if(A >= k) {
                cout << "no" << "\n"; return 0;
            }
            if(dp[L][R] == s[L] + dp[L+2][R]){
                B += (s[L+1] == 'V');
                if(B >= k){
                    cout << "yes" << "\n"; return 0;
                }
                L += 2;
            }else{
                B += (s[R] == 'V');
                if(B >= k){
                    cout << "yes" << "\n"; return 0;
                }
                L += 1; R -= 1;
            }
        }else if(dp[L][R] == ((s[R] == 'V') + max(dp[L+1][R-1],dp[L][R-2]))){
            A += (s[R] == 'V');
            if(A >= k) {
                cout << "no" << "\n"; return 0;
            }
            if(dp[L][R] == s[R] + dp[L+1][R-1]){
                B += (s[L] == 'V');
                if(B >= k){
                    cout << "yes" << "\n"; return 0;
                }
                L += 1; R -= 1;
            }else{
                B += (s[R-1] == 'V');
                if(B >= k){
                    cout << "yes" << "\n"; return 0;
                }
                R -= 2;
            }
        }
    }
    return 0;
}


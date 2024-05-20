#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 22;
int n,a,b;
string s; 

// n<=18 a,b<=100
// 1.显然必须使高位尽可能大
// 2.对于加操作尽可能的多操作指导'9',对于减操作尽可能的减少到x->0->9,如果不能减少到9则不操作
// 3.对于同一位 如果都可以 加到9,减到9, 操作次数完全足够 考虑到n<=18枚举每一位使用的操作是+/- 总时间复杂度O(2^n*n)
void solve(){
    cin>>s>>a>>b;
    n = s.length();
    int ans = stoll(s);
    for(int i=0;i<(1LL<<n);i++){
        int numa = a, numb = b;
        vector<int> vec(n); 
        for(int j=0;j<n;j++) vec[j] = s[j] - '0';
        
        for(int j=0;j<n;j++){
            int v = (i >> j) & 1;
            if(v == 0){ 
                while(numa > 0 && vec[j] < 9) {
                    vec[j] += 1;
                    numa -= 1;
                } 
            }else{
                if(numb >= vec[j] + 1){
                    numb -= (vec[j] + 1);
                    vec[j] = 9;
                }
            }
        }
        
        int res = 0;
        for(int j=0;j<n;j++) res = res * 10 + vec[j];
        ans = max(ans, res);
    }
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}

/*
123 1 2
933
*/

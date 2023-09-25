// #include <bits/stdc++.h>
// #define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
// using namespace std;
// const int N = 1e5 + 10;
// int n;
// int dp[N][10]; //dp[i,j] 表示前i个数字以j结尾的最长长度

// struct Node{
//     int l,r;
// };

// int main(){
//     IOS; 
//     cin>>n;
//     vector<Node> vec(n+1);
//     for(int i=1;i<=n;i++){
//         string s; cin>>s;
//         vec[i] = {s.front()-'0',s.back()-'0'};
//     }    
//     dp[1][vec[1].r] = 1;
//     for(int i=2;i<=n;i++){
//         for(int j=0;j<10;j++) dp[i][j] = dp[i-1][j];
//         dp[i][vec[i].r] = max(dp[i-1][vec[i].l]+1,dp[i][vec[i].r]);
//     }
//     int maxx = 0;
//     for(int j=0;j<10;j++) maxx = max(maxx,dp[n][j]);
//     cout << n - maxx << "\n";
//     return 0;
// }

#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e5 + 10;
int n;
int dp[10]; //dp[i,j] 表示前i个数字以j结尾的最长长度

struct Node{
    int l,r;
};

int main(){
    IOS; 
    cin>>n;
    vector<Node> vec(n+1);
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        vec[i] = {s.front()-'0',s.back()-'0'};
    }    
    dp[vec[1].r] = 1;
    for(int i=2;i<=n;i++){
        // for(int j=0;j<10;j++) dp[i][j] = dp[i-1][j];
        dp[vec[i].r] = max(dp[vec[i].l]+1,dp[vec[i].r]);
    }
    int maxx = 0;
    for(int j=0;j<10;j++) maxx = max(maxx,dp[j]);
    cout << n - maxx << "\n";
    return 0;
}
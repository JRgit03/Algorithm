#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e5 + 10;
int n;
int h[N];

int gcd(int a,int b){
    return b ? gcd(b, a % b) : a;
}

int lcm(int a,int b){
    return a * b / gcd(a, b);
}

int calc(int a,int b,int c){
    return (__int128)a * b * c * lcm(lcm(a, b), c) / (lcm(a,b) * lcm(a,c) * lcm(b,c));
}

void solve(){
   cin>>n;
   for(int i=1;i<=n;i++) cin>>h[i];
   sort(h+1, h+1+n);
   if(n <= 100){
       int maxx = -1;
       vector<int> ans(3);
       for(int i=1;i<=n;i++){
           for(int j=i+1;j<=n;j++){
               for(int k=j+1;k<=n;k++){
                   int res = calc(h[i],h[j],h[k]);
                   if(res > maxx){
                       maxx = res;
                       ans[0] = h[i], ans[1] = h[j], ans[2] = h[k];
                   }
               }
           }
       }
       for(auto &x : ans) cout << x << " ";
   }else{
       // s = gcd(a, b, c)
       int up = 100000;
       vector<int> d[up+10];
       for(int i=1;i<=n;i++){
           for(int j=1;j*j<=h[i];j++){
               if(h[i] % j == 0){
                   d[j].push_back(h[i]);
                   if(h[i] / j != j) d[h[i] / j].push_back(h[i]); 
               }
           }
       }
       for(int j=up;j>=1;j--){
           if(d[j].size() >= 3){
               for(int k=0;k<3;k++) cout << d[j][k] << " ";
               return;
           }
       }
   }
}

signed main(){
    IOS;
    solve();
    return 0;
} 

/*
5
1 2 3 4 9
*/

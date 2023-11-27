#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int f(int a,int b,int c){
    vector<int> vec = {a,b,c}; sort(vec.begin(),vec.end());
    return __gcd(vec[0],vec[1]);
}
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                ans += f(a[i],a[j],a[k]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

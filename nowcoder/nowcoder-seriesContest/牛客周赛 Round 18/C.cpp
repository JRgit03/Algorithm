#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n,k,ans1,ans2;
int a[maxn];
map<int,int> mp;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i]; a[i] %= k; //cout << a[i] << " "; 
        if(a[i]) {
            if(mp[k-a[i]] > 0){
                mp[k-a[i]]--;
                ans2 += 1;
            }else{
                mp[a[i]]++;
            }
        }else ans1 += 1;
    }
    cout << ans1 + ans2<< "\n";
    return 0;
}

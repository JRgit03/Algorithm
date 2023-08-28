#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e6 + 10;
int n;
int a[N];

signed main(){ 
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    
    int sum=0,cnt=0,res=0;

    int l = 1 , r = n;

    for(;l<=r;){
        //cout << r << " " << (sum+a[r])/(cnt+1) << " " << a[r] << "\n";
        if((double)(sum+a[r])/(cnt+1) < a[r]){
            sum += a[r--] , cnt++ , res++;
        }else{
            sum += a[l++] , cnt++;
        }
        //cout << l << " " << r << "\n";
    }
    cout << res << "\n";
    return 0;
}

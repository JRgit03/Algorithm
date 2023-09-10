#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
int main(){
    IOS;
    int n,m,ans;
    cin>>n>>m;
    if(m<n) swap(m,n);
    if(m==n) ans=2*n-2;
    else if(m%n==0) ans=(m/n-2)*n+3*n-2;
    else{
        ans=m/n*n+n;
        int y=m%n;
        ans+=max(0,n-2-2*(n-y));
    }
    cout<<ans<<endl;
    return 0;
}

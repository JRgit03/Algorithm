#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 510;

int a[N][N];
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans1=0,ans2=0;
        for(int i=1;i<=n;i++){
            int min1=1e7;
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
                min1=min(min1,a[i][j]);
            }
            ans1+=min1;
        }
        for(int i=1;i<=n;i++){
            int min2=1e7;
            for(int j=1;j<=n;j++){
                min2=min(min2,a[j][i]);
            }
            ans2+=min2;
        }
        cout<<min(ans1,ans2)<<endl;
    }
    return 0;
}
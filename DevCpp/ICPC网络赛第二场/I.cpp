#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int a[N],q[N];
double pow(double a,int b){
    double ans=1;
    while(b){
        if(b&1) ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        double ans=n;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) scanf("%d",&q[i]);
        for(int i=0;i<n;i++){
            double res=0;
            if(q[i]!=0){
                double p=q[i]*1.0/100000;
                int t=i+1;
                for(int j=0;j<100;j++){
                    res+=t*pow(1.0-p,j)*p;
                    t+=i-a[i]+1;
                }
                ans=min(ans,res);
            }
            
        }
        printf("%.12f\n",ans);
    }
    return 0;
}
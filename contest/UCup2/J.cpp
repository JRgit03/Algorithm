#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N=1e5+10;
int x[N],y[N];
int main(){
    IOS;
    int n,t,sx,sy,tx,ty;
    int num1,num2;
    cin>>n>>t>>sx>>sy>>tx>>ty;
    int ix1,iy1,ix2,iy2;
    double ans=sqrt(1.0*(sx-tx)*(sx-tx)+1.0*(sy-ty)*(sy-ty));
    double mina=1e5,minb=1e5;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        if(abs(x[i]-sx)<mina){
            mina=abs(x[i]-sx);
            ix1=x[i];iy1=sy;num1=i;
        }
        if(abs(y[i]-sy)<mina){
            mina=abs(y[i]-sy);
            iy1=y[i];ix1=sx;num1=i;
        }
        if(abs(x[i]-tx)<minb){
            minb=abs(x[i]-tx);
            ix2=x[i];iy2=ty;num2=i;
        }
        if(abs(y[i]-ty)<minb){
            minb=abs(y[i]-ty);
            iy2=y[i];ix2=tx;num2=i;
        }
    }
    //cout<<mina<<" "<<minb<<endl;
    //cout<<num1<<" "<<num2<<endl;
    //for(int i=1;i<=n;i++) cout<<x[i]<<" "<<y[i]<<endl;
    if(num1!=num2) t+=t;
    if(mina+minb+t<ans){
        ans=min(mina+minb+t,ans);
        int cnt=3;
        if(!mina) cnt--;
        if(!minb) cnt--;
        if(num1!=num2) cnt++;
        cout<<ans<<endl<<cnt<<endl;
        if(mina) cout<<0<<" "<<ix1<<" "<<iy1<<endl;
        cout<<num1<<" "<<x[num1]<<" "<<y[num1]<<endl;
        cout<<num2<<" "<<ix2<<" "<<iy2<<endl;
        if(minb) cout<<0<<" "<<tx<<" "<<ty<<endl;
    }
    else{
        cout<<ans<<endl<<1<<endl;
        cout<<0<<" "<<tx<<" "<<ty<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

int mouth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void is_run(int y){
    if((y%4==0&&y%100!=0)||y%400==0) mouth[2]=29;
    else mouth[2]=28;
}

int main(){
    IOS;
    int n;
    cin>>n;
    int begin=3,ans=0;
    for(int i=1970;i<=n;i++){
        is_run(i);
        for(int j=1;j<=12;j++){
            if(i==n) {
                //cout<<j<<" "<<(mouth[j]-(7-begin)+6)/7+1<<endl;
                ans+=(mouth[j]-(7-begin)+6)/7+1;}
            begin=(mouth[j]-(7-begin))%7;
        }
    }
    cout<<ans<<endl;
    return 0;
}

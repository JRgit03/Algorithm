#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

signed main(){
    IOS;
    int n;string str;cin>>n>>str; str = "?" + str;
    vector<int> vec(n+1);
    for(int i=1;i<=n;i++){
        char c = str[i];
        if(c=='1') vec[i] = 1;
        else if(c=='4') vec[i] = 2;
        else vec[i] = 0;
    }
    //for(int i=1;i<=n;i++) cout << vec[i] << " \n"[i==n];
    int res = 0;
    for(int i=1;i<=n;i++){
        if(vec[i]==1){
            int x = 1;
            int l = i-1 , r = i+1;
            while(r<=n && vec[r]!=2)r++,x++;    
            //cout << "1 " << l << " " << r << " " << x << "\n"; 
            res += x*(x+1)/2; i=r-1;
        }else if(vec[i]==2){
            int x = 1;
            int l = i-1 , r = i+1;
            while(r<=n && vec[r]!=1)r++,x++;
            //cout << "2 "  <<  l << " " << r << " " << x << "\n";
            res += x*(x+1)/2; i=r-1;
        }
    }
    cout << res << "\n";
    return 0;
}

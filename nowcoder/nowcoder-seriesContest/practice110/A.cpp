#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

signed main(){
    IOS;
    int n;string str;cin>>n>>str;
    str = "?" + str;
    vector<int> a,b;
    int f1=0,f2=0;
    for(int i=1;i<=n;i++){
        char c = str[i];
        if(c=='4')a.push_back(i) , f1 = 1;
        if(c=='1')b.push_back(i) , f2 = 1;
    }

    if((f1+f2==1) || f1+f2==0){
        cout << n * (n+1) / 2 << "\n";return 0;
    }

    int res = 0;
    for(int i=0;i<a.size();i++){
        int L,R;
        int l=0,r=b.size()-1;
        while(l<r){
            int mid = l + r + 1>> 1;
            if(b[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        if(b[r] > a[i]) L = 0;
        else L = b[r];
        l=0,r=b.size()-1;
        while(l<r){
            int mid = l + r>> 1;
            if(b[mid] > a[i]) r = mid;
            else l = mid + 1;
        }
        if(b[r] < a[i]) R = n+1;
        else R = b[r];
        //cout << L << " " << R << "\n";
        res += (a[i]-L) * (R-a[i]);
    }
    //cout << res << "\n";
    for(int i=0;i<b.size();i++){
        int L,R;
        int l=0,r=a.size()-1;
        while(l<r){
            int mid = l + r + 1>> 1;
            if(a[mid] < b[i]) l = mid;
            else r = mid - 1;
        }
        if(a[r] > b[i]) L = 0;
        else L = a[r];
        l=0,r=a.size()-1;
        while(l<r){
            int mid = l + r>> 1;
            if(a[mid] > b[i]) r = mid;
            else l = mid + 1;
        }
        if(a[r] < b[i]) R = n+1;
        else R = a[r];
        //cout << L << " " << R << "\n";
        res += (b[i]-L) * (R-b[i]);
    }
    cout << res << "\n";
    return 0;
}

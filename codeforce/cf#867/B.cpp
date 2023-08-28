#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;cin>>n;bool flag = false;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x>0)a.push_back(x);
        else if(x<0)b.push_back(x);
        else flag = true;
    } 
    sort(a.begin(),a.end());reverse(a.begin(),a.end());
    sort(b.begin(),b.end());
    int maxa=-1,maxb=-1,res=-1;
    if(a.size() >= 2) maxa = a[0] * a[1];
    if(b.size() >= 2) maxb = b[0] * b[1];
    if(maxa!=-1 && maxb!=-1){
        res = max(maxa,maxb);
    }else if(maxa!=-1 && maxb==-1){
        res = maxa;
    }else if(maxa==-1 && maxb!=-1){
        res = maxb;
    }else if(a.size()==1 && b.size()==1){
        res = a[0] * b[0];
    }
    if(flag) res = max(res , 1LL*0);
    cout << res << "\n";
}

signed main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}

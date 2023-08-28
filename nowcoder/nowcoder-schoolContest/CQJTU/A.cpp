#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1010,Mod=1e9+7;
int n,d1,d2;
int tr[N];

int lowbit(int x){
    return x&-x;
}

void add(int x,int c){
    for(int i=x;i<=n;i+=lowbit(i)) tr[i] = (tr[i]+c)%Mod;
}

int sum(int x){
    int res = 0;
    for(int i=x;i;i-=lowbit(i)) res = (res + tr[i])%Mod;
    return res;
}

signed main(){
    IOS;
    cin>>n>>d1>>d2;
    add(1,1),add(2,-1);
    for(int i=1;i<=n;i++){
        int s = sum(i); //cout << s << "\n";
        add(i+d1,s) , add(i+d2,-s);
    }
    int res = 0;
    for(int i=n;i>n-d2;i--){
        //cout << sum(i) << "\n";
        res = (res + sum(i))%Mod;
    }
    cout << res << "\n";
    return 0;
}

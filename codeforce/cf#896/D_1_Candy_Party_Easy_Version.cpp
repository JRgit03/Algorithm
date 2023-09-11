#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;

int lowbit(int x){
    return x & (-x);
}

void solve(){
    int n; cin>>n;
    vector<int> a(n); for(auto &x : a) cin>>x;
    int sum = accumulate(a.begin(),a.end(),0LL);
    if(sum % n != 0){
        cout << "No" << "\n";
        return;
    }
    int avg = sum / n;
    map<int,int> bit;
    // 2^xi - 2^yi = abs(a[i] - avg)  => 2^xi + dif = 2^yi
    for(int i=0;i<n;i++){
        if(a[i] == avg) continue;
        int dif = abs(a[i] - avg);
        int xi = lowbit(dif); //尽可能处理dif的最后一位1 使得 和 为 2^yi
        int yi = dif + xi;
        if(__builtin_popcount(yi) == 1){ //__builtin_popcount(x) 返回二进制位为1的个数
            if(a[i] > avg) bit[__lg(yi)]++ , bit[__lg(xi)]--;
            else bit[__lg(xi)]++ , bit[__lg(yi)]--;
        }else{
            cout << "No" << "\n";
            return;
        }
    }
    
    for(auto &[_,cnt] : bit)
        if(cnt){
            cout << "No" << "\n";
            return;
        }
    
    cout << "Yes" << "\n";
    return;
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}

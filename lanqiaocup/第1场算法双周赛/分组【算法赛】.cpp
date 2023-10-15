#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n,k;
int h[N];

int check(int maxdif){
    int minn = -1 , maxx = -1 , sz = 0;
    for(int i=1;i<=n;i++){
        if(maxx == -1){
            minn = h[i] , maxx = h[i];
        }else{
            minn = min(minn,h[i]);
            maxx = max(maxx,h[i]);
            if(maxx - minn > maxdif){
                sz += 1;
                minn = h[i] , maxx = h[i];
            }
        }
    }
    if(minn != -1 && maxx != -1) sz += 1;
    return sz <= k;
}

int main(){
    IOS;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>h[i];
    sort(h+1,h+1+n);
    int l = 0 , r = 2e9;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << "\n";
    return 0;
}

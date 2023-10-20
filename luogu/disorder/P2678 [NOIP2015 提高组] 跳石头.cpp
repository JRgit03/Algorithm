#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 5e4 + 10;
int n,m;
int ed,d[N];

bool check(int minS){
    int cnt = 0 , pre = d[0];
    for(int i=1;i<=n+1;i++){
        if(d[i] - pre >= minS) pre = d[i];
        else cnt++;  
    }
    return cnt <= m;
} 

int main(){
    IOS;
    cin>>ed>>n>>m; d[n+1] = ed;
    for(int i=1;i<=n;i++) cin>>d[i];
    int l = 0, r = ed;
    while(l < r){ //二分最短跳跃距离
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r << "\n";
    return 0;
}

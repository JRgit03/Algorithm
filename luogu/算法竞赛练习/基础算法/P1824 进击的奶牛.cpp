#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n,c;
int x[N];

bool check(int maxw){
    int cnt = 1 , pre = x[1];
    for(int i=2;i<=n;i++)
        if(x[i] - pre >= maxw){
            pre = x[i];
            cnt++;
        }
    return cnt >= c;
}

void solve(){
    cin>>n>>c;
    for(int i=1;i<=n;i++) cin>>x[i]; 
    sort(x+1,x+1+n);
    int l = 0 , r = 1e9;
    while(l<r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }    
    cout << r << "\n";
}

int main(){
    IOS; solve();
    return 0;
}

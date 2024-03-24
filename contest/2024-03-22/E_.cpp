#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n;
int x[N],l[N];
int b[N];

int max(int a,int b){
    return a >= b ? a : b;
}

void solve(){
    cin>>n;
    x[0] = 0, l[0] = 1;
    for(int i=1;i<=n;i++) cin>>x[i]>>l[i];
    for(int i=1;i<=n;i++){
        int dx = x[i] - x[i-1];
        int dy = l[i] - l[i-1];
        if(dy >= 0){
            if(dx < dy){
                l[i] = min(l[i], l[i-1] + dx);
            }
        }else{
            dy = -dy;
            if(dx < dy){
                b[i-1] -= dy - dx; b[i] += dy - dx;
            }
        }
    }
    for(int i=1;i<=n;i++) { 
        b[i] += b[i-1]; //cout << b[i] << "\n";
        l[i] = max(1, l[i] + b[i]);
        //printf("l[%d] = %d\n", i, l[i]);
    }
    int ans = 1;
    for(int i=1;i<=n;i++){
        int dx = x[i] - x[i-1], dy = abs(l[i] - l[i-1]);
        int c = max(dx - dy, 0);
        ans = max(ans, l[i] + c / 2);
    }
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
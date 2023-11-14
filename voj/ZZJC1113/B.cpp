#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int ans = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n/i;j++)
            ans += n / (i * j);
    cout << ans << "\n";
    return 0;
}

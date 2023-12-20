#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int ans;

int a[N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(i >= 2 && a[i] - a[i-1] >= 0){
            ans += a[i] - a[i-1];
        }
    }
    cout << ans << "\n";
    return 0;
}

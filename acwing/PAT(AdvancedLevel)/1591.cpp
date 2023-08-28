#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N];
int l[N],r[N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    l[0] = 0 , r[n+1] = 0x3f3f3f3f;
    for(int i=1;i<=n;i++) l[i] = max(l[i-1],a[i]);
    for(int i=n;i>=1;i--) r[i] = min(r[i+1],a[i]);
    vector<int> res;
    for(int i=1;i<=n;i++)
        if(a[i] > l[i-1] && a[i] < r[i+1])
            res.push_back(a[i]);
    cout << res.size() << "\n";
    if(res.size()){
        cout << res[0];
        for(int i=1;i<res.size();i++) cout << " " << res[i];
    }
    return 0;
}

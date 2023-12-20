#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n,k,q;
int a[maxn],b[maxn];

void add(int l,int r,int c){
    b[l] += c, b[r+1] -= c;
}

int main(){
    cin>>n>>k>>q;
    for(int i=0;i<n;i++){
        int l,r; cin>>l>>r;
        add(l,r,1);
    }
    for(int i=1;i<=200000;i++) b[i] += b[i-1] , a[i] = (b[i] >= k);
    for(int i=1;i<=200000;i++) a[i] += a[i-1];
    while(q--){
        int l,r; cin>>l>>r;
        cout << a[r] - a[l-1] << "\n";
    }
    return 0;
}

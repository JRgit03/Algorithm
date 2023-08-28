#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,x;cin>>n>>k>>x;
    vector<vector<int>> a(n);
    int cur = 1;
    for(int i=0;i<n;i++){
        vector<int> tmp,b(n);
        for(int i=0;i<n;i++) cin>>b[i];
        if(i&1) {
            a[i] = b; continue;
        }
        for(int i=0;i<cur;i++) tmp.push_back(x);
        for(int i=0;i<n-cur;i++) tmp.push_back(b[i]);
        cur++; if(cur==k+1) cur=1;
        a[i] = tmp;
    }
        
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=0;j<n;j++)    
            sum += a[j][i];
        if(!i) cout << sum;
        else cout << " " << sum;
    }
    return 0;
}
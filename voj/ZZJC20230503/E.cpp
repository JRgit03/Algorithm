#include <bits/stdc++.h>
using namespace std;

void answer(int k){
    cout << "!" << " " << k << "\n";
} 

void query(int sum , int l , int r){
    cout << "?" << " " << sum;
    for(int i=l;i<=r;i++) cout << " " << i ; 
    cout << "\n";
}

void solve(){
    int n;cin>>n;
    vector<int> s(n+1);
    for(int i=1;i<=n;i++) cin>>s[i] , s[i] += s[i-1];
    
    int l = 1 , r = n;

    int q=0;while(++q<=30){
    	//cout << l << " " << r << "\n";
        if(l==r) {
            answer(r); return;
        }
        int mid = l + r>> 1;
        int tar = s[mid] - s[l-1];
        query(mid-l+1,l,mid);

        int in; cin>>in;
        if(in == tar) l = mid + 1;
        else if(in != tar) r = mid;
    }
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}

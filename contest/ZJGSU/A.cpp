#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    IOS;
    int n;cin>>n;
    vector<int> v;
    for(int i=0;i<n-1;i++){
        int x;cin>>x;
        v.push_back(x);
    }
    int tar;cin>>tar;
    sort(v.begin(),v.end());
    int l=0,r=v.size()-1;
    while(l<r){
        int mid = l + r + 1 >> 1;
        if(v[mid] < tar) l = mid;
        else r = mid-1;
    }
    if(v[r] < tar)cout << r+1 << "\n";
    else cout << 0 << "\n";
    return 0;
}

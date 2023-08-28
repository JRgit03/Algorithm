#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int n;
int a[N];

bool check(int k){
    
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    
    int resl , resr;
    
    int l = 1 , r = n;
    while(l<r){
        int mid = l+r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    return 0;
}

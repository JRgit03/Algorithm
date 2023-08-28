#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1010;
int n,m;
int w[N];
int l,r;

bool check(int maxsum){
    int ne = 0,sum=0;
    for(int i=1;i<=n;i++){
        sum += w[i];
        if(sum > maxsum){
            ne++;
            sum = w[i];
        }else if(sum==maxsum){
            ne++;
            sum = 0;
        }
    }
    if(sum)ne++;
    //cout << ne << " " << maxsum << "\n";
    return m>=ne;
}

int main(){
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        l = max(l,w[i]);
        r += w[i];
    }  
    while(l<r){
        int mid = l+r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(check(r)) cout << r << "\n";
    else cout << 0 << "\n";
    return 0;
}

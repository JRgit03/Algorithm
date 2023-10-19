// 找至少出现k次的最长重复子串len
#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10 , P = 13331;
int n,k;
int str[N];
typedef unsigned long long ULL;
ULL h[N],p[N],rh[N];

ULL gethash(int l,int r){
    return h[r] - h[l-1] * p[r-l+1];
}

ULL getrhash(int l,int r){
    return rh[l] - rh[r+1] * p[r-l+1];
}

void init(){
    p[0] = 1;
    for(int i=1;i<=n;i++){
        h[i] = h[i-1] * P + str[i];
        rh[n-i+1] = rh[n-i+1+1] * P + str[n-i+1]; 
        p[i] = p[i-1] * P;
    }
}

bool check(int len){
    map<ULL,int> cnt; int maxx = -1;
    for(int i=1;i+len-1<=n;i++){
        ULL hash = gethash(i,i+len-1);
        maxx = max(maxx, ++cnt[hash]);
    }
    return maxx >= k;
}

int main(){
    cin>>n>>k; 
    for(int i=1;i<=n;i++) cin>>str[i];
    init();
    int l = 1, r = n;
    while(l<r){
        int mid = l+r+1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << (check(r) ? r : 0) << "\n";
    return 0; 
}
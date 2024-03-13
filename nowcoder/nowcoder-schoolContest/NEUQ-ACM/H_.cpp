#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,d;
int s[N],p[N];

struct Node{
    int isD,fs,rk;

    bool operator < (const Node &o) const {
        return fs > o.fs;
    }
};

int main(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    int i1 = d, i2 = 1;
    vector<Node> vec;
    for(;i1<=n;){
        if(i2 == 1) vec.push_back({1,s[i1] + p[i2],0});
        else vec.push_back({0,s[i1] + p[i2], 0});
        i1 += 1; i2 += 1;
    }
    i1 = 1;
    int l = i2, r = n;
    while(l <= r){
        if(s[i1] + p[r] <= vec[0].fs) {
            vec.push_back({0, s[i1] + p[r], 0});
            i1 += 1; r -= 1;
        }else{
            vec.push_back({0, s[i1] + p[l], 0});
            i1 += 1; l += 1;
        }
    }
    sort(vec.begin(), vec.end());
    vec[0].rk = 1;
    int ans = 1;
    for(int i=1;i<n;i++){
        if(vec[i].fs == vec[i-1].fs) vec[i].rk = vec[i-1].rk;
        else vec[i].rk = vec[i-1].rk + 1;
        if(vec[i].isD) ans = vec[i].rk;
    }
    cout << ans << "\n";
    return 0;
}

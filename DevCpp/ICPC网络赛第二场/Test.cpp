#include <bits/stdc++.h>
using namespace std;

struct Node{
    double a,b,p;

    bool operator < (const Node &t) const {
        return a+b*p < t.a+t.p*t.b;
    }
};

void solve(){
    int n; cin>>n;
    vector<Node> vec;
    for(int i=0;i<n;i++){
        double a,b,p; cin>>a>>b>>p;
        vec.push_back({a,b,p});
    }
    sort(vec.begin(),vec.end());
    double ans = 0 , t = 0;
    for(int i=0;i<n;i++){
        auto [a,b,p] =  vec[i];
        t += a+b*p;
        ans += t;
    }
    printf("%.12lf\n",ans);
}

int main(){
    int t; cin>>t;
    while(t--)solve();
    return 0;
}
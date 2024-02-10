#include <bits/stdc++.h>
using namespace std;

struct Node{
    int a,b;
    bool operator < (const Node& o) const {
        return a != o.a ? a > o.a : b < o.b;
    }
};

int main(){
    int n; cin>>n;
    vector<Node> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i].a>>vec[i].b;
    }  
    sort(vec.begin(), vec.end());
    int ans = 1;
    for(int i=1;i<n;i++){
        if(vec[i].a != vec[i-1].a || vec[i].b != vec[i-1].b){
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}

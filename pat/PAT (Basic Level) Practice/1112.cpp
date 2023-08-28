#include <bits/stdc++.h>
using namespace std;

struct Node{
    string id;
    int sum,cnt;
};

int main(){
    int n;cin>>n;
    vector<Node> vec(n);
    for(int i=0;i<n;i++){
        string a;int b,c;cin>>a>>b>>c;
        vec[i] = {a,b*c,c};
    }
    sort(vec.begin(),vec.end(),[](const Node p1,const Node p2){
        return p1.cnt > p2.cnt;
    });
    cout << vec[0].id << " " << vec[0].cnt << "\n";

    sort(vec.begin(),vec.end(),[](const Node p1,const Node p2){
        return p1.sum > p2.sum;
    });
    cout << vec[0].id << " " << vec[0].sum << "\n";
    return 0;
}

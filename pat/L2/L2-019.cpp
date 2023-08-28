#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    map<string,bool> st;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        st[s] = true;
    }
    int m;cin>>m;
    int sum = 0;
    vector<pair<string,int> > vec(m);
    for(int i=0;i<m;i++){
        string s;int x;cin>>s>>x;
        vec[i]={s,x};
        sum += x;
    }
    double avg = sum / m;

    cout << "avg:" << avg << "\n";

    vector<string> res;
    for(int i=0;i<m;i++){
        auto [a,b] = vec[i];
        if(b * 1.0 > avg && !st[a]) res.push_back(a);
    }
    sort(res.begin(),res.end());
    for(auto s : res)
        cout << s << "\n";

    if(!res.size())
        cout << "Bing Mei You" << "\n";
    return 0;
}

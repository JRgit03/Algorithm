#include <bits/stdc++.h>
using namespace std;

map<string,set<int> > mp;
map<string,int> sum;

struct Node{
    string name;
    int cnt , sum;

    bool operator < (const Node &t) const {
        if(cnt!=t.cnt) return cnt > t.cnt;
        return 1.0 * cnt / sum > (1.0 * t.cnt / t.sum);
    }
};

int main(){
    int n;cin>>n;
   
    for(int i=0;i<n;i++){
        string s;int k;cin>>s>>k;
        sum[s] = k;
        while(k--){
            int x;cin>>x;
            mp[s].insert(x);
        }
    }

    vector<Node> vec;

    for(auto &[s,st] : mp){
        vec.push_back({s,(int)st.size(),sum[s]});
        //cout << s << " " << st.size() << " " << sum[s] << "\n";
    }

    sort(vec.begin(),vec.end());
    
    for(int i=0;i<3;i++){
        if(i!=0)cout<<" ";
        if(i<(int)vec.size())cout<<vec[i].name;
        else cout<<"-";
    }
   return 0;
}

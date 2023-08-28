#include <bits/stdc++.h>
using namespace std;
int D,P;

struct Node{
    string name,sfz;
    int state;
    string time;
    int id;

    bool operator < (const Node &t) const {
        if(time!=t.time) return time < t.time;
        return id < t.id;
    }    
};

bool check(string s){
    int cnt = 0;  for(auto c : s) cnt += (c>='0' && c<='9'); return cnt==18;
}

int main(){
    cin>>D>>P;
    map<string,int> mp;
    map<string,bool> st;
    vector<pair<string,string>> res;

    for(int day=1;day<=D;day++){
        int t,s;cin>>t>>s;
        vector<Node> vec;
        for(int i=1;i<=t;i++){
            string a,b,d;int c,id=i;
            cin>>a>>b>>c>>d;//cout<<a<<" "<<b<<" "<<c<<" " << d << "\n"; 
            if(check(b)){
                vec.push_back({a,b,c,d,id});
                if(c==1 && !st[b]){
                    res.push_back({a,b});
                    st[b] = true;
                }
            }
        }

        sort(vec.begin(),vec.end());

        for(int i=0;i<(int)vec.size();i++){
            auto [a,b,c,d,id] = vec[i];

            //if(a=="A") cout << a << " " << mp[a] << "\n";
            if(mp[b]==0 && s>0){
                cout << a << " " << b << "\n";
                mp[b] = P;
                s--;
            }
        }
        for(auto &[a,b] : mp) if(b>0) b--;
    }  

    for(auto [a,b] : res)
        cout << a << " " << b << "\n";
    return 0;
}

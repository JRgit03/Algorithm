#include <bits/stdc++.h>
using namespace std;
typedef pair<string,string> PSS;

struct Node{
    string name,sfz,state,time;
    int id;
    bool operator < (const Node &t) const {
        if(time!=t.time) return time < t.time;
        return id < t.id;
    }
};

unordered_map<string,int> exits;
vector<PSS> bad;

unordered_map<string,int> mp;

bool check(string s){
    if(s.length()!=18) return false;
    for(auto c : s)
        if(c < '0' || c > '9') 
            return false;
    return true;
}

int main(){
    int D,P;cin>>D>>P;
    for(int day=1;day<=D;day++){
        int t,s;cin>>t>>s;
        vector<Node> vec(t);
        for(int i=0;i<t;i++){
            string a,b,c,d;int id=i+1;
            cin>>a>>b>>c>>d;vec[i] = {a,b,c,d,id};
            if(!check(b))continue;
            if(c=="1" && !exits[b]) {
                bad.push_back({a,b});
                exits[b] = 1;
            }
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<t&&s;i++){
            auto [a,b,c,d,id] = vec[i];
            if(!check(b))continue;
            if(day >= mp[b] || !mp[b]){
                //cout << mp[b] <<" " << day+P+1 << " cur=" << day << "\n"; 
                cout << a << " " << b << "\n";
                mp[b] = day+P+1;
                s--;
            }
        }
    }
    //cout << "\n";
    for(auto [a,b] : bad) cout << a << " " << b << "\n";
    return 0;
}

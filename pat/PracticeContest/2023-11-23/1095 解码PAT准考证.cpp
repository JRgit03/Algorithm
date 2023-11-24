/**
 *  暴力模拟 X STL的使用 √ 
 */
#include <bits/stdc++.h>
using namespace std;
int n,m;
map<string,vector<pair<string,int>>> m1; // {pat级别,[{准考证号,成绩},....]}
map<string,pair<int,int>> m2; // {考场号,[人数,总分]}
map<string,map<string,int>> m3;// {日期, {考场,人数}} 

// 可以把 map 看出一维数组 map[k] = v
// mp[rq][kc] += 1;

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s; int fs; cin>>s>>fs; // A 112 180318 002   fs:98
        string a = s.substr(0,1),b = s.substr(1,3),c = s.substr(4,6),d = s.substr(10);
        m1[a].push_back({s,fs});
        m2[b].first += 1, m2[b].second += fs;
        m3[c][b] += 1;
    }    
    for(int T=1;T<=m;T++){
        int op; cin>>op;
        printf("Case %d: ", T);
        if(op == 1){
            string s; cin>>s; cout << 1 << " " << s << "\n";
            if(!m1.count(s)){
                cout << "NA" << "\n";
                continue;
            }
            sort(m1[s].begin(),m1[s].end(),[&](pair<string,int> &p,pair<string,int> &q){
                return (p.second != q.second ? p.second > q.second : p.first < q.first); 
            });
            for(auto [a,b] : m1[s]) cout << a << " " << b << "\n";
        }else if(op == 2){
            string kc; cin>>kc; cout << 2 << " " << kc << "\n";
            if(!m2.count(kc)){
                cout << "NA" << "\n";
                continue;
            }
            cout << m2[kc].first << " " << m2[kc].second << "\n";
        }else if(op == 3){
            string rq; cin>>rq; cout << 3 << " " << rq << "\n";
            if(!m3.count(rq)){
                cout << "NA" << "\n";
                continue;
            }
            vector<pair<string,int>> vec;
            for(auto [a,b] : m3[rq]) vec.push_back({a,b});
            sort(vec.begin(),vec.end(),[&](auto &p,auto &q){
                return (p.second != q.second ? p.second > q.second : p.first < q.first); 
            });
            for(auto [kc,sz] : vec) cout << kc << " " << sz << "\n";
        }
    }
    return 0;
}

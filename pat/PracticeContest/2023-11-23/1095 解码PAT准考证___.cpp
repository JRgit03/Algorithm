/**
 *  操作1： 统计-指定级别(T A B)-按分数非升序(=>非严格降序)输出 考生信息 成绩相同按准考证字典序小的输出
 *  操作2： 统计-指定考场- 输出 人数 与 总分数
 *  操作3： 统计-指定日期-分考场-输出人数 非升序输出
 * 
 * // eg:  
 * // B - 123 - 180908 - 127 => (级别 - 考场号 - 考试日期 - 考生编号)
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int n,q;

struct Node{
    string s;
    int fs;
}v[maxn];

int main(){
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>v[i].s>>v[i].fs;
    for(int T=1;T<=q;T++){ // O(n * m)
        int op; string s; cin>>op>>s;
        printf("Case %d:",T); cout << " " << op << " " << s << "\n";
        if (op == 1){
            vector<Node> vec;
            for(int i=1;i<=n;i++){
                if(v[i].s.substr(0,1) == s){
                    vec.push_back(v[i]);
                }
            }
            if(!vec.size()){
                cout << "NA" << "\n"; continue;
            }
            sort(vec.begin(),vec.end(),[&](Node &p, Node & q){
                return (p.fs != q.fs ? p.fs > q.fs : p.s < q.s); 
            });
            for(auto [a,b] : vec) cout << a << " " << b << "\n";
        }else if(op == 2){
            int sz = 0, sum = 0;
            for(int i=1;i<=n;i++){
                if(v[i].s.substr(1,3) == s){
                    sz += 1;
                    sum += v[i].fs;
                }
            }
            if(sz == 0){
                cout << "NA" << "\n"; continue;
            }
            cout << sz << " " << sum << "\n";
        }else if(op == 3){
            map<string,int> cnt; // [考场号,对应人数]
            for(int i=1;i<=n;i++){
                string rq = v[i].s.substr(4,6), kc = v[i].s.substr(1,3);
                if(rq == s){
                    cnt[kc] += 1;
                }
            }
            if(cnt.size() == 0){
                cout << "NA" << "\n"; continue;
            }
            vector<pair<string,int>> ans; // [考场,指定考场的人数]
            for(auto [a,b] : cnt) ans.push_back({a,b});
            sort(ans.begin(),ans.end(),[&](auto &p, auto &q){
                return (p.second != q.second ? p.second > q.second : p.first < q.first);
            });
            for(auto [a,b] : ans) cout << a << " " << b << "\n";
        }
    }
    return 0;
}
